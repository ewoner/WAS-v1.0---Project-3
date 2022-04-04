#ifndef LISTENERMANAGER_HPP
#define LISTENERMANAGER_HPP

#include "../Connections/connectionmanager.hpp"

class ListenerManager {
public:
    ListenerManager();
    ~ListenerManager();
    void run();
    void setConnectionManager( ConnectionManager );
    void isRunning();

private:
     int listenerSocket;
     bool running;
     ConnectionManager conManager;
     

};


#endif
