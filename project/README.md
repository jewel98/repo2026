# Networked Tic-Tac-Toe (Instructor Solution)

This solution implements a **single two-player match** of console-based Tic-Tac-Toe over TCP sockets. It has no graphical dependencies and requires no multithreading. The server owns the board and applies all game rules.

## Files

- `server.c` — server, authoritative 3×3 board, move validation, win/draw logic, turn sequencing.
- `client.c` — TCP client, board display, command input, game status.
- `PROJECT_DESCRIPTION.md` — student-facing assignment (share without the solution files).

## Platform

Linux, macOS, GCP, or Windows Subsystem for Linux (WSL). The code uses **POSIX sockets**; native Windows compilation would require Winsock adaptations. GCC or Clang can compile the sources.

## Compile

```bash
gcc -std=c11 -Wall -Wextra -pedantic server.c -o server
gcc -std=c11 -Wall -Wextra -pedantic client.c -o client

or simply,
gcc server.c -o server
gcc client.c -o client
```

## Run on one laptop (three terminals)

```bash
# Terminal 1: server
./server 5000

# Terminal 2: first player (X)
./client 127.0.0.1 5000

# Terminal 3: second player (O)
./client 127.0.0.1 5000
```

The second client must connect before the game starts. The first player is X. At each turn, enter a square number 1–9. The client shows available squares as digits and occupied squares as X or O. Type `q` to quit. The server exits after one match; restart it to play again.

To run across computers on the same LAN, replace `127.0.0.1` with the server machine's reachable IPv4 address, and allow the port through any host firewall. No public internet is needed for localhost or LAN play.

## Application protocol

All messages are **UTF-8/ASCII text terminated by a newline** (`\n`). The solution has explicit send loops and line readers because TCP is a byte stream and does not preserve message boundaries.

| Direction | Example | Meaning |
|---|---|---|
| Server → client | `ROLE X` | Assign a player symbol |
| Server → client | `INFO Waiting for Player O...` | Informational status |
| Server → both | `BOARD X.O...O..` | Exactly nine squares, row-major; `.` means empty |
| Server → both | `TURN X` | Current player's symbol |
| Server → current player | `YOUR_TURN` | Prompt that player to send a move |
| Client → server | `MOVE 5` | Choose square 5 (center) |
| Server → current player | `INVALID Enter an empty square numbered 1-9.` | Move rejected; same player tries again |
| Client → server | `QUIT` | Resign/leave |
| Server → both | `RESULT X_WINS` | X wins |
| Server → both | `RESULT O_WINS` | O wins |
| Server → both | `RESULT DRAW` | Board filled without winner |
| Server → survivor | `RESULT OPPONENT_DISCONNECTED` | Opponent disconnected or quit |

Example sequence: X plays 1, O plays 2, X plays 5, O plays 3, X plays 9, and X wins the diagonal.

## Important design choices

- **No threads:** The server uses blocking I/O for the player whose turn it is. The other client waits for updates. This works because Tic-Tac-Toe is turn-based.
- **Authoritative server:** Clients only propose moves. The server checks range, occupancy, and game rules before updating the board.
- **Graceful disconnection:** After a detected disconnect, the server notifies the other client and terminates the match.
- **Limitations:** One two-player match per run; no reconnection, authentication, scoreboard, turn timer, or support for multiple simultaneous games. These are optional extensions.


