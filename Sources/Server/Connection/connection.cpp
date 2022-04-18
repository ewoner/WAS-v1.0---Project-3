#include "connection.hpp" 
#include <limits>
#include <ctime>
#include <fcntl.h>
#include <iostream>
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
	handler->setConnection( this );
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
	threadLock.lock();
	writeBuf << data << "\n";
	threadLock.unlock();
}
void Connection::sendToClient( ){
	threadLock.lock();
	int bytes = writeBuf.str().size();
	if ( bytes == 0 ) {
		threadLock.unlock();
		return;
	}
	std::cerr << "-----------:Initalliy\n" << writeBuf.str() << "\n ....\n";
	char * toSend = new char[bytes+1]{};
	writeBuf.read( toSend, bytes );
	std::cerr << "-----------:Sending\n" << writeBuf.str() << "\n ....\n";
	std::cout << "Connection.sendToClient() " << conSocket << writeBuf.str() << "\n";
	write ( conSocket, toSend, bytes );
	writeBuf.str( std::string() );
	std::cerr << "-----------:After getlines\n" << writeBuf.str() << "\n ....\n";
	threadLock.unlock();
}
void Connection::receiveFromClient() {
	std::cerr << "-----------:Getting Data!\n" << readBuf.str() << "\n ....\n";
	char * received = new char[4097]{};
	read ( conSocket, received,4096 );
	readBuf << *received;
	handler->handle( readBuf.str() );
	delete [] received;
	std::cerr << "-----------:After getlines\n" << readBuf.str() << "\n ....\n";
}

