#ifndef CONNECTIONMANAGER_HPP
#define CONNECTIONMANAGER_HPP

//#include <sys/socket.h>
#include <netinet/in.h>

class ConnectionManager {
public:
    ConnectionManager();
    ~ConnectionManager();

    void newConnection( int, struct sockaddr, socklen_t );
private:


};
#endif