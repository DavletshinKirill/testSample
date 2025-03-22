#include "Client.h"

#define CONNECTION_ERROR 1;

Client::Client()
{
    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        throw CONNECTION_ERROR;
    }
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    result = getaddrinfo(SERVER_IP, PORT, &hints, &addrResult);
    if (result != 0) {
        std::cerr << "getaddrinfo failed: " << result << std::endl;
        WSACleanup();
        throw CONNECTION_ERROR;
    }

    connectSocket = socket(addrResult->ai_family, addrResult->ai_socktype, addrResult->ai_protocol);
    if (connectSocket == INVALID_SOCKET) {
        std::cerr << "socket failed: " << WSAGetLastError() << std::endl;
        freeaddrinfo(addrResult);
        WSACleanup();
        throw CONNECTION_ERROR;
    }
    result = connect(connectSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
    if (result == SOCKET_ERROR) {
        std::cerr << "connect failed: " << WSAGetLastError() << std::endl;
        closesocket(connectSocket);
        connectSocket = INVALID_SOCKET;
    }

    freeaddrinfo(addrResult);

    if (connectSocket == INVALID_SOCKET) {
        std::cerr << "Unable to connect to server!" << std::endl;
        WSACleanup();
        throw CONNECTION_ERROR;
    }
}

void Client::SendData()
{
    send(connectSocket, message, strlen(message), 0);
}

void Client::ReadData()
{
    int bytesReceived = recv(connectSocket, buffer, BUFFER_SIZE, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0'; // Null-terminate the string
        std::cout << "Received from server: " << buffer << std::endl;
    }
}

Client::~Client()
{
    std::cout << "Destructor Client";
    closesocket(connectSocket);
    WSACleanup();
}
