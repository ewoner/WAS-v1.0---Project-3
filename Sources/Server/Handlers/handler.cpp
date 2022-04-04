#include "handler.hpp"

Handler::Handler() : Handler( nullptr ) {}
Handler::Handler( Connection * con ) : connection (con) {}
    
void Handler::enter() {}
void Handler::leave() {}
void Handler::handle( std::string data ) {}