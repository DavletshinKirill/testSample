#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // Подключение библиотеки Winsock

#define PORT 8080
#define BUFFER_SIZE 1024

class Server
{
private:
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int addrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE] = {0};

public:
    Server();
    ~Server();
    void ReadDataFromClient();
    void SendResponceToClient();
};