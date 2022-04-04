#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <string>

//Forward Declarations
class Connection;

class Handler {
public:
    Handler();
    Handler( Connection * );

    virtual void leave();
    virtual void enter();
    virtual void handle( std::string data );

private:
    Connection * connection;
};

#endif