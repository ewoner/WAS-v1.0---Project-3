#ifndef LISTENERMANAGER_HPP
#define LISTENERMANAGER_HPP

class ListenerManager {
public:
    ListenerManager();
    void start();
    void finalize();
    void setConnectionManager( ConnectionManager );
    void setRunning( bool );
    bool isRunning();

private:
    // List of ServerSocketChannels
    ConnectionManager conManager;
    //final int max = 10;
    //Selector acceptSelector;
    bool running;

};


#endif