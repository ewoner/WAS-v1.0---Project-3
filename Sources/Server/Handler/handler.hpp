#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <string>

#include "../Account/account.hpp"

class Connection;

class Handler {
public:
	Handler();
	void leave();
	void enter();
	void handle( std::string);
	void setConnection( Connection* );
private:
	Account account;
	Connection* connection;
	std::string state;
	
	void logon();
};
#endif
