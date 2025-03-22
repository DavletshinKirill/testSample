#include "Client.h"

#define CONNECTION_ERROR 1;

Client::Client()
{
    WSADATA wsaData;
    SOCKET sock;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE] = {0};

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "Initialization Exception Winsock." << std::endl;
        throw CONNECTION_ERROR;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        std::cerr << "Socket Creation Exception." << std::endl;
        WSACleanup();
        throw CONNECTION_ERROR;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "Connection Refuse." << std::endl;
        closesocket(sock);
        WSACleanup();
        throw CONNECTION_ERROR;
    }
}

void Client::SendData(char *message)
{
    send(sock, message, strlen(message), 0);
    std::cout << "Message Sent." << std::endl;
}

void Client::ReadData()
{
    int bytesReceived = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytesReceived > 0)
    {
        std::cout << "Server reply: " << buffer << std::endl;
    }
    else
    {
        std::cerr << "Server reply error" << std::endl;
    }
}

Client::~Client()
{
    std::cout << "Destructor Client";
    closesocket(sock);
    WSACleanup();
}
