#include <iostream>
#include <winsock2.h>
#include <chrono>
#include <thread>

#pragma comment(lib, "ws2_32.lib") // Подключение библиотеки Winsock

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int addrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE] = {0};

    // Инициализация Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Initialization Error Winsock." << std::endl;
        return 1;
    }

    // Создание сокета
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Socket Creation Error." << std::endl;
        WSACleanup();
        return 1;
    }

    // Настройка адреса сервера
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Привязка сокета к адресу
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Socket Connection Error." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Начало прослушивания
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Apply Error." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server started. Wait for connection..." << std::endl;

    // Принятие подключения
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error connection." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    while (true) {
    
    // Чтение данных от клиента
    int bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0);
    if (bytesRead > 0) {
        std::cout << "Get from client: " << buffer << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    // Отправка ответа клиенту
    const char* response = "Got data!";
    send(clientSocket, response, strlen(response), 0);
    std::cout << "Responce was sent for client." << response << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    // Закрытие сокетов
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
