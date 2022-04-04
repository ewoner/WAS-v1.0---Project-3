#include "listenermanager.hpp"
ListenerManager.ListenerManager() {
    //initialize socket
    //create socket
    //turn off blocking
    //bind socket
}
ListenerManager.finalize() {
    //close socket
}
void start() {
    this->running = true;
    while ( isRunning() ) {
        //Get new connections
        //Add new connections to conManager        
    }
}
void setConnectionManager( ConnectionManager conManager ) {
    this->conManager = conManager;
}

bool isRunning() {
    return this->running;
}