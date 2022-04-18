#include "handler.hpp"
#include "../Connection/connection.hpp"
Handler::Handler() {
	state = "logon";
}

void Handler::handle(std::string data) {
	if ( state == "logon" ) {
		if ( data == "1" ) {
			logon();
		}
		else if ( data == "2" ) {
			logon();
		}
	}
	
}

void Handler::leave() {}

void Handler::enter() {
	connection->BufferDatatoSend("Welcome!\n Press 1 to Login\n Press 2 to Register\n Type \'exit\' to Quit");
}
void Handler::setConnection( Connection * con ) {
	connection = con;
}

void Handler::logon() {
	static std::string logonState = "name";
	if ( logonState == "name" ) {
		connection->BufferDatatoSend("Enter name:");
		logonState = "password";
	}
	else if ( logonState == "password" ) {
			connection->BufferDatatoSend("Enter password: " );
			logonState = "name";
	}
}
