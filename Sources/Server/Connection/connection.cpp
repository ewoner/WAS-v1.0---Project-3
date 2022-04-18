#include "connection.hpp" 
#include <limits>
#include <ctime>
#include <fcntl.h>
Connection::Connection( ) : Connection::Connection( -1, {}, 0, 0 ) {}
Connection::Connection( int conS, struct sockaddr add,  socklen_t addLen, long time ) 
:conSocket( conS ), creationTime( time ), closed( false ), lastSendTime( time ),checkSendTime( false ),
address( add ), addressLen( addLen ) {
	
	
    fcntl(conSocket, F_SETFL, O_NONBLOCK);
	}
Connection::~Connection() {
	if ( handler != nullptr ) {
		delete handler;
	}
}

void Connection::bufferData( std::string data ) {
	sendBuffer << data;
}

long Connection::getLastSendTime() {
	return lastSendTime;
}
Handler* Connection::getHandler() {
	return handler;
}
void Connection::addHandler() {
	handler = new Handler;
}
void Connection::closeSocket() {
	close( conSocket );
	if ( getHandler() != nullptr ) {
		getHandler()->leave();
	}
}
long Connection::getCreationTime() {
	return creationTime;
}
bool Connection::isClosed() {
	return closed;
}
void Connection::BufferDatatoSend( std::string data ) {
	writeBuf << data << "\r\n";
}
void Connection::sendToClient( ){
	while ( writeBuf.str().size() > 0 ) {
		char * toSend = new char[4049]{};
		writeBuf.read( toSend, 4048 );
		write ( conSocket, toSend, 4048 );
		delete [] toSend;
	}
}
void Connection::receiveFromClient() {
	char * received = new char[4049]{};
	read ( conSocket, received,4048 );
	readBuf << *received;
	handler->handle( readBuf.str() );
	delete [] received;
}

