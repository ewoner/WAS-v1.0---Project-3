#ifndef CONNECTIONMANAGER_HPP
#define CONNECTIONMANAGER_HPP

#include <vector>
#include <netinet/in.h>
#include <mutex>
#include "../Connection/connection.hpp"

class ConnectionManager {
public:
    ConnectionManager();
    ~ConnectionManager();

    void newConnection( int, struct sockaddr, socklen_t );
    void closeConnections();
    void listen();
    void send();
    void manage();
    void close(Connection*);
    void shutdown();
private:
	std::vector<Connection*> connections;
	std::mutex threadLock;

};
#endif
