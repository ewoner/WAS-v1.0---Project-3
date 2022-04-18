#include "connectionmanager.hpp"
#include <ctime>
#include <algorithm>
#include <iostream>
ConnectionManager::ConnectionManager(){}
ConnectionManager::~ConnectionManager(){
		shutdown();
}
void ConnectionManager::newConnection( int sock, struct sockaddr addr, socklen_t addrlen ){
	std::cout << "ConnectionManager::NewConnection( "<< sock << ")\n";
	Connection * newCon = new Connection( sock, addr, addrlen, time( nullptr) );
	newCon->addHandler();
	connections.push_back( newCon );
	newCon->getHandler()->enter();
}
void ConnectionManager::closeConnections() {
	//~ std::cout << "ConnectionManager::close()\n";
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
	//~ std::cout << "ConnectionManager::listen()\n";
	std::vector<Connection*> toListen ( connections );
	for ( auto con : toListen ) {
		con->receiveFromClient();
	}
	threadLock.unlock();
}

void ConnectionManager::send() {
	threadLock.lock();
	//~ std::cout << "ConnectionManager::send()\n";

	std::vector<Connection*> toListen ( connections );
	for ( auto con : toListen ) {
		con->sendToClient();
	}
	threadLock.unlock();
}

void ConnectionManager::manage() {
	//~ std::cout << "ConnectionManager::manage()\n";
	listen();
	send();
	closeConnections();
}

void ConnectionManager::close( Connection * con ) {
		
		exit(100);
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
