# Minitalk

[한국어 버전](README.md.kr)

## Overview
Minitalk is a project that demonstrates inter-process communication (IPC) using UNIX signals. The goal is to implement a client-server communication system where the client sends a string message to the server, and the server displays it.

- **Objective:** Learn about UNIX signals and implement basic inter-process communication.
- **Key Features:**
  - Communication between client and server using `SIGUSR1` and `SIGUSR2`.
  - Ability to send and receive string messages.
  - Support for Unicode characters.

## Features
- **Client-Server Communication:**
  - The client sends a message character by character to the server using signals.
  - The server decodes the signals and prints the received message to the console.
- **Signal Handling:**
  - Use of `SIGUSR1` and `SIGUSR2` signals for binary encoding of characters.
  - Acknowledgment of message delivery by the server.
- **Robustness:**
  - Handles large strings and ensures message integrity.

## Requirements
- **Operating System:** Linux or macOS.
- **Dependencies:** None (standard C library and POSIX system calls used).

## Installation and Execution
### Clone the Repository
```bash
git clone [repository URL]
cd minitalk
```

### Build
```bash
make
```

### Run
1. start the server:
```bash
./server
```
The server will display its PID (Process ID).

2. Send a message from the client:
```bash
./client [server PID] "Your message here"
```

### Example
1. Start the server:
```bash
./server
```

Output:
```bash
Server PID: 12345
```

2. Send a message from the client:
```bash
./client 12345 "Hello, Minitalk!"
```

Output on server:
```bash
Message received: Hello, Minitalk!
```

### File Structure
- `srcs/`: Source code files.
- `head/`: Header files.
- `Makefile`: Build script for the project.

### How It Works
- The client encodes each character of the message into binary format.
- Each bit is sent to the server as a signal (SIGUSR1 for 0, SIGUSR2 for 1).
- The server decodes the signals into characters and reconstructs the original message.

### References
- UNIX Signals
- Inter-process Communication