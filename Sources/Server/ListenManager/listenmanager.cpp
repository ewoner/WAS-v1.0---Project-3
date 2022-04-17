#include "listenmanager.hpp"
#include "../was_presets.hpp"

#include <iostream>

ListenManager::ListenManager() {
    conManager = nullptr;
    listenSocket = -1;
    port = PORT;
    running = false;
    listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    fcntl(listenSocket, F_SETFL, O_NONBLOCK);}
 ListenManager::~ListenManager(){
     if ( listenSocket > -1 ) {
         //close the socket
     }
     if ( conManager != nullptr ) {
         delete conManager;
     }
 }

void ListenManager::init( ConnectionManager * newManager ) {
    conManager = newManager;
    if ( conManager == nullptr ) {
        exit( 1 );
    }
    struct sockaddr_in  my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons ( PORT );
    my_addr.sin_addr.s_addr = htonl (INADDR_ANY);
    int b = bind (listenSocket, (struct sockaddr *) &my_addr, sizeof (my_addr));
    if ( b == -1 ) exit ( 1 );
    running = true;
     std::cout << "Listen Manager(" << listenSocket << ") started in port " << port << std::endl;
}

void ListenManager::start() {
    int l = listen( listenSocket, 1 );
    if ( l == -1 ) exit ( 2 );
    while ( running ) {
        struct sockaddr cli_addr;
        socklen_t  clilen;
        clilen = sizeof (cli_addr);
        int clientSocket = accept (listenSocket, (struct sockaddr * ) &cli_addr, &clilen);
        if ( clientSocket > 0 ) {
            std::cout << "Accepting new client!!!!" << clientSocket << std::endl;
            conManager->newConnection( clientSocket, cli_addr, clilen );
        }
    }
}
void ListenManager::stop() {
    running = false;
}