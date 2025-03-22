#include "Server.h"

#define CONNECTION_ERROR 1;

Server::Server()
{
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "Initialization Error Winsock." << std::endl;
        throw CONNECTION_ERROR;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
    {
        std::cerr << "Socket Creation Error." << std::endl;
        WSACleanup();
        throw CONNECTION_ERROR;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "Socket Connection Error." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        throw CONNECTION_ERROR;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cerr << "Apply Error." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        throw CONNECTION_ERROR;
    }

    std::cout << "Server started. Wait for connection..." << std::endl;

    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cerr << "Error connection." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        throw CONNECTION_ERROR;
    }
}

Server::~Server()
{
    std::cout << "Destructor Server";
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
}

void Server::ReadDataFromClient()
{
    int bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0);
    if (bytesRead > 0)
    {
        std::cout << "Get from client: " << buffer << std::endl;
    }
}

void Server::SendResponceToClient()
{
    const char *response = "Got data!";
    send(clientSocket, response, strlen(response), 0);
    std::cout << "Responce was sent for client." << std::endl;
}
