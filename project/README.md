# Programming Project: Networked Tic-Tac-Toe

**Language:** C  
**Topics:** TCP sockets, two-dimensional arrays, conditions, loops, functions, and client–server applications.

## Objective

Develop a two-player Tic-Tac-Toe game. Two client programs connect to a central TCP server. The server maintains the authoritative game board, validates moves, enforces turns, and announces wins or draws. Players may use separate computers or three terminals on one computer.

## Part A – Game board and rules

1. Represent the board with a `char board[3][3]` array.
2. First player is **X**; second player is **O**.
3. Players select squares numbered 1 through 9:

   ```text
    1 | 2 | 3
   ---+---+---
    4 | 5 | 6
   ---+---+---
    7 | 8 | 9
   ```

4. Reject out-of-range and occupied squares without advancing the turn.
5. After each legal move, check all rows, columns, and diagonals for three identical symbols.
6. If the board fills without a winner, report a draw.

## Part B – TCP server (`server.c`)

- Listen on a user-specified TCP port and accept two clients.
- Assign X to the first client and O to the second.
- Keep the authoritative board and turn status.
- Receive and validate moves; send the updated board to both clients.
- Announce whose turn it is, reject invalid moves, and report game results.
- Handle a client disconnecting or quitting.

## Part C – TCP client (`client.c`)

- Connect using a server IPv4 address and TCP port.
- Display the assigned symbol, board, and turn information.
- Read a move only when prompted, then send it to the server.
- Display invalid-move feedback, wins, draws, or disconnect notices.

## Technical rules

- Implement the project in C using TCP sockets.
- Use arrays, loops, conditions, and functions.
- Keep game logic on the server; the client must not decide whether a move succeeds.
- Use a documented text protocol with a clear boundary between messages (e.g., newline-terminated commands). Remember that TCP is a byte stream: a single `recv()` does not necessarily return a complete message.
- A text-only terminal interface is sufficient. No graphical interface or multithreading is required.
- One match per server execution is sufficient.

## Compilation and execution (Linux / WSL)

```bash
gcc -std=c11 -Wall -Wextra -pedantic server.c -o server
gcc -std=c11 -Wall -Wextra -pedantic client.c -o client
```

Open three terminals in the same environment:

```bash
# Terminal 1
./server 5000

# Terminal 2
./client 127.0.0.1 5000

# Terminal 3
./client 127.0.0.1 5000
```

For clients on different computers, replace `127.0.0.1` with the reachable server IPv4 address.

## Deliverables

1. `server.c` — TCP server and game logic.
2. `client.c` — TCP client and terminal interface.
3. `README.md` — build/run instructions and short design explanation.
4. Screenshots showing both clients connected and a completed match.

## Grading (100 points)

| Criterion | Points |
|---|---:|
| Board implementation and display | 10 |
| Move validation and turn management | 15 |
| Winner and draw detection | 15 |
| Server and two TCP connections | 20 |
| Client–server communication and board updates | 20 |
| Functions and program organization | 10 |
| Documentation and demonstration | 10 |
| **Total** | **100** |

## Optional extra credit

Rematches, player names, persistent scoreboard, simultaneous independent games, or timed turns.
