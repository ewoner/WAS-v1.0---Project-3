#ifndef LISTENMANAGER_HPP
#define LISTENMANAGER_HPP

#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>

#include "../ConnectionManager/connectionmanager.hpp"

class ListenManager {
public:

    ListenManager();
    ~ListenManager();

    void init(ConnectionManager*);
    void start();
    void stop();
    

private:
    ConnectionManager * conManager;
    int listenSocket;
    int port;    
    bool running;

};

#endif