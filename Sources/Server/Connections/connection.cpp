#include "connection.hpp"

Connection::Connection(): socket( -1 ), creationTime( 0 ), closed( true ) {
    recvBuffer = new char[MAX_BUFFER_SIZE]{};
    sendBuffer = new char[MAX_BUFFER_SIZE]{};
}

Connection::Connection( unsigned int s ) : Connection() {
    socket = s;
    closed = false;
}

int Connection::getSocket(){
    return this->socket;
}
void Connection::switchHandler( Handler & newHandler ){
    this->removeHandler();
    this->addHandler( newHandler );
}
void Connection::addHandler( Handler & addHandler ){
    this->getHandler().leave();
    this->handlers.push( addHandler );
    this->getHandler().enter();

}
void Connection::removeHandler( ){
    this->getHandler().leave();
    this->handlers.pop();
    this->getHandler().enter();
}
Handler & Connection::getHandler(){
    return this->handlers.top();
}
void Connection::clearHandlers(){
    this->removeHandler();
    while ( this->handlers.size() < 0 ) {
        this->handlers.pop();
    }
}

long Connection::getCreationTime(){
    return this->creationTime;
}
long Connection::getLastSendTime(){
    return this->lastSendTime;
}

void Connection::close(){
    this->closed = true;
}
bool Connection::isClosed(){
    return this->closed;
}

int Connection::send( std::string data ){
    int sent = 0;
    while ( sent < data.size() ) {
        std::string sendingData = data.substr(sent, MAX_BUFFER_SIZE);
        int toSendSize = sendingData.size();
        if ( write( socket, (void*)this->sendBuffer, toSendSize) == -1 ) {
            std::cerr << "Could not send to the server. : " << errno << std::endl;
            break;
        }
        sent += toSendSize;
        
    }
    return sent;
}
void Connection::receive(){
   if ( read( socket, (void*)this->recvBuffer, MAX_BUFFER_SIZE )  == -1 ) {
       std::cerr << "Could not receive data from the server. : " << errno << std::endl;
   }
}