#include "connectionmanager.hpp"
#include <ctime>
#include <algorithm>

ConnectionManager::ConnectionManager(){}
ConnectionManager::~ConnectionManager(){
		shutdown();
}
void ConnectionManager::newConnection( int sock, struct sockaddr addr, socklen_t addrlen ){
	Connection * newCon = new Connection( sock, addr, addrlen, time( nullptr) );
	newCon->addHandler();
	connections.push_back( newCon );
}
void ConnectionManager::closeConnections() {
	threadLock.lock();
	std::vector<Connection*> toClose( connections );
	for ( auto con : toClose ) {
		if ( con->isClosed() ) {
			this->close( con );
		}
	}
	threadLock.unlock();
}

void ConnectionManager::listen() {
	threadLock.lock();
	std::vector<Connection*> toListen ( connections );
	for ( auto con : toListen ) {
		con->receiveFromClient();
	}
	threadLock.unlock();
}

void ConnectionManager::send() {
	threadLock.lock();
	std::vector<Connection*> toListen ( connections );
	for ( auto con : toListen ) {
		con->sendToClient();
	}
	threadLock.unlock();
}

void ConnectionManager::manage() {
	listen();
	send();
	closeConnections();
}

void ConnectionManager::close( Connection * con ) {
	con->closeSocket();
	auto itr = find( connections.begin(), connections.end(), con );
	connections.erase( itr );
	delete *itr;
}
void ConnectionManager::shutdown(){
	threadLock.lock();
	for ( auto con : connections ) {
		close( con );
	}
	
	threadLock.unlock();
	
}
