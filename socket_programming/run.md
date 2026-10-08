**Compile**

gcc server.c -o server

gcc client.c -o client

**Run**

./server

./client


**Run with IP and Port**

./server 5000

./client 192.168.10.10 5000


...

gcc -Wall -Wextra server.c -o server

gcc -Wall -Wextra client.c -o client

...

argv[0] = "./client"

argv[1] = "192.168.10.10"

argv[2] = "5000"

...

**Compile:**

gcc -Wall -Wextra server.c -o server

**Run:**

./server 5000

The client should connect using the server computer’s IP and the same port:

./client 192.168.10.223 5000
