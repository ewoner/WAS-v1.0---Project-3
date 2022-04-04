#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <unistd.h>
#include <sys/socket.h>

#include <iostream>
#include <stack>
#include <string>

#include "./Handlers/handler.hpp"
#include "../was_presets.hpp"


class Connection {
public:
    Connection();
    Connection( unsigned int socket );

    int getSocket();

    void switchHandler( Handler & newHandler );
    void addHandler( Handler & addHandler );
    void removeHandler( );
    Handler & getHandler();
    void clearHandlers();

    long getCreationTime();
    long getLastSendTime();

    void close();
    bool isClosed();
    
    int send( std::string data );
    void receive();

private:
    unsigned int socket;
    std::stack<Handler> handlers;
    long creationTime;
    long lastSendTime;
    bool closed;
    char * recvBuffer;
    char * sendBuffer;
};


#endif