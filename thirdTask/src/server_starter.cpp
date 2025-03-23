#include "Server.cpp"

int main() 
{
    Server* server = new Server();
    server->ReadDataFromClient();
    server->SendResponceToClient();
    delete server;
    return 0;
}