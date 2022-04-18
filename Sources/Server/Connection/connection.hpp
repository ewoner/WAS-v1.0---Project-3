#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <stack>
#include <sstream>
#include <netinet/in.h>
#include <unistd.h>

#include "../Handler/handler.hpp"

class Connection {
public:
    Connection();
    Connection( int, struct sockaddr, socklen_t, long );
    ~Connection();
    
    void bufferData( std::string );
    long getLastSendTime();
    void closeSocket();
    Handler* getHandler();
    void addHandler();
    long getCreationTime();
    bool isClosed();
    void BufferDatatoSend( std::string data );
    void sendToClient();
    void receiveFromClient();
private:
	int conSocket;
	Handler *handler;
	long creationTime;
	bool closed;
	std::stringstream readBuf;
	std::stringstream writeBuf;
	std::stringstream sendBuffer;
	long lastSendTime;
	bool checkSendTime;
	struct sockaddr address; 
	socklen_t addressLen;

};
#endif
