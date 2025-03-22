#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // Подключение библиотеки Winsock

#define PORT 8080
#define BUFFER_SIZE 1024

class Client
{
private:
    WSADATA wsaData;
    SOCKET sock;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE] = {0};

public:
    Client();
    void SendData(char *message);
    void ReadData();
    ~Client();
};