# 🎮 Guess the Number Game over UDP (C)

A simple terminal-based client-server game built using **UDP sockets in C**. The server randomly selects a number between 1 and 100. The client sends guesses, and the server responds with **"Higher"**, **"Lower"**, or **"Correct!"** until the number is guessed correctly.

---

## 📌 Objectives

- Understand and implement **UDP socket programming** in C.
- Create a basic **connectionless client-server** architecture.
- Demonstrate **stateless communication** using UDP.
- Reinforce concepts of **message passing, string parsing**, and **game logic**.

---

## 🔧 Features

### ✅ Server
- Generates a random number (1–100).
- Listens for incoming guesses from clients via UDP.
- Replies with:
  - `Higher` if guess is too low.
  - `Lower` if guess is too high.
  - `Correct!` if guess is accurate (and resets number).

### ✅ Client
- Takes input from the user via terminal.
- Sends guesses to the server.
- Displays server's response.
- Terminates on correct guess.

---

## 🖥️ Platform

- OS: **Linux / Unix-like**
- Language: **C**
- Sockets: **POSIX (Berkeley) Sockets)**
- Protocol: **UDP (User Datagram Protocol)**

---

## ⚙️ How to Compile

Make sure you have GCC installed.

### Compile the server:
```bash
gcc server.c -o server



