#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define SERVER_IP "127.0.0.1"
#define PORT "8080"
#define BUFFER_SIZE 1024

class Client
{
private:
    WSADATA wsaData;
    SOCKET connectSocket;
    addrinfo hints = {};
    addrinfo* addrResult;
    int result;
    const char* message = "Hello from client!";
    char buffer[BUFFER_SIZE];

public:
    Client();
    void SendData();
    void ReadData();
    ~Client();
};