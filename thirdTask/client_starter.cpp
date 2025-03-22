#include <iostream>
#include "Client.cpp"

int main() {
    Client* client = new Client();
    client->SendData();
    client->ReadData();
    delete client;
    return 0;
}