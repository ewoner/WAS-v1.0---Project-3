#ifndef CONNECTIONMANAGER_HPP
#define CONNECTIONMANAGER_HPP

#include <vector>

class Connection;

class ConnectionManager {
public:
    static const int MAX_DATA_RATE = 1024;
    static const int SEND_TIME_OUT = 60;
    static const int MAX_BUFFERED = 8 * MAX_DATA_RATE;
    
    ConnectionManager();
    
    void addNewConnection( int );
    void closeAllConnections();
    void listen();
    void send();
    void manage();
    void close( int );
    void shutdown();
    

    
    
private:
    std::vector<Connection> connections;
};

#endif
