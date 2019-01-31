# GroupChat-C
A simple group chat server that one can write using C/C++, with the support of external websocket router.
**websocketd** is a binary, that provides a CGI like interface for applications, websocketd can redirect all STDIN and STDOUTs to user-program.

Checkout the repository **websocketd** for more information.

### How to run : 

The bootstrap program is written in C and it's compiled binary is provided, this bootstrap program requires a port number as argument.
The bootstrap program compiles **Server.c** and launches the compiled binary by wrapping it inside websocketd.

You have to run this simple command to start:
```
./bootstrap 8000    #800 = PORT
```
Run test.py to interact with the server program.
