#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT "8080"
#define BUFFER_SIZE 1024

class Server
{
private:
    WSADATA wsaData;
    int result;
    addrinfo hints = {};
    addrinfo* addrResult;
    SOCKET listenSocket, clientSocket;
    char buffer[BUFFER_SIZE];
    const char* response = "Hello from server!";

public:
    Server();
    ~Server();
    void ReadDataFromClient();
    void SendResponceToClient();
};