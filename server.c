#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    // Seed random number
    srand(time(NULL));
    int secret_number = rand() % 100 + 1;

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Bind server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return 1;
    }

    printf("Server is running on port %d\n", PORT);
    printf("Secret number: %d\n", secret_number);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);

        int guess = atoi(buffer);
        char response[BUFFER_SIZE];

        if (guess == 0 && buffer[0] != '0') {
            snprintf(response, sizeof(response), "Invalid input. Enter a number.");
        } else if (guess < secret_number) {
            snprintf(response, sizeof(response), "Higher");
        } else if (guess > secret_number) {
            snprintf(response, sizeof(response), "Lower");
        } else {
            snprintf(response, sizeof(response), "Correct! You guessed it.");
            // Reset the number
            secret_number = rand() % 100 + 1;
            printf("New secret number: %d\n", secret_number);
        }

        sendto(sockfd, response, strlen(response), 0, (struct sockaddr *)&client_addr, addr_len);
    }

    close(sockfd);
    return 0;
}
