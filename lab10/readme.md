This demo demonstrates a basic TCP client–server communication using POSIX sockets in C.

There are two separate components:
- server that listens for incoming TCP connections
- client that connects to the server, sends a message, and receives a response

The communication happens locally on `127.0.0.1` (localhost) using port `12345`.

## Server side
1. Creates a TCP socket (`AF_INET`, `SOCK_STREAM`).
2. Binds the socket to all network interfaces (`INADDR_ANY`) on port `12345`.
3. Listens for incoming connections.
4. Accepts client connection.
5. Reads a message sent by the client.
6. Prints the received message to the console.
7. Sends a response back to the client.
8. Closes the client connection and shuts down.

# Client side

1. Creates a TCP socket.
2. Connects to the server at `127.0.0.1:12345`.
3. Sends a message to the server.
4. Waits for a response.
5. Prints the response received from the server.
6. Closes the connection.

