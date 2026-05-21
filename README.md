
<img width="1200" height="506" alt="Screen-Recording-final" src="https://github.com/user-attachments/assets/b3ce9b31-cb65-4e75-8e78-27acc10ad53f" />

# minitalk

A client-server communication program using Unix signals, built as part of the 42 curriculum.

## How it works

Messages are transmitted **bit by bit** using only two signals:
- `SIGUSR1` → bit `0`
- `SIGUSR2` → bit `1`

The client decomposes each character into 8 bits and sends the corresponding signal for each one. The server reconstructs the characters from the received bits and prints them.

The bonus version adds an **acknowledgment system**: the server sends `SIGUSR1` back to the client after each received bit, and `SIGUSR2` once the full message is received. This makes the transmission reliable — the client waits for confirmation before sending the next bit.

## Compilation

```bash
# Mandatory
make

# Bonus
make bonus
```

## Usage

### Mandatory

```bash
# Terminal 1 — start the server (it prints its PID)
./server

# Terminal 2 — send a message
./client <server_pid> <message>
```

### Bonus

```bash
# Terminal 1
./server_bonus

# Terminal 2
./client_bonus <server_pid> <message>
```

The bonus client prints `OK!` once the server has acknowledged the full message.

## Difference between mandatory and bonus

| Feature | Mandatory | Bonus |
|---|---|---|
| Signal transmission | `SIGUSR1` / `SIGUSR2` | `SIGUSR1` / `SIGUSR2` |
| Acknowledgment | No | Yes (per bit + end of message) |
| Reliability | Basic (`usleep` delay) | Guaranteed (wait for ACK) |
| Unicode support | No | No |
