#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <sstream>
#include <stack>
#include <string>

#include "connectionmanager.hpp"

class Handler;

class Connection {
public:
    Connection();
    Connection( int );
    //socket member operations
    int getSocket();
    
    //handlers member operations
    void addHandler( Handler );
    void clearAllHandlers();
    Handler getHandler();
    void removeHandler( Handler );
    void swithHandler( Handler );
    
    //creationTime member operations
    long getCreationTime();
    
    //close member operations
    void close();
    bool isClosed();
    
    //sendBuffer member operations
     int getLengthToSend();
    void bufferData( std::string );
    
    //lastSendTime member operations
    long getLastSendTime();
    
    //Send, receive, close socket operations
    void sendTheBuffer();
    int send( std::string );
    void receive();
    void closeSocket();
    

    
    
private:
    int socket;
    std::stack<Handler> handlers;
    long creationtime;
    bool closed;
    std::stringbuf readBuffer, writeBuffer;
    const int BUFFERSIZE = ConnectionManager::MAX_BUFFERED + 1;   
    std::stringbuf sendBuffer;
    long lastSendTime;
    
    void prepWriteBuffer( std::string );
    std::string readRequest( );
    
};

#endif
