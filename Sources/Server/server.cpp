#include "./ListenManager/listenmanager.hpp"
#include <unistd.h>
#include <iostream>
#include <thread>

void test() {}
int main( int nargs, char ** args ) {
    ListenManager * lm = new ListenManager;
    lm->init (new ConnectionManager() );
    std::thread t( test );
    lm->stop();
    exit(100);
    //Parse Command line arguements
    
    //set and fork a ListenerManager
    
    //main loop
    while ( true /*server.isRunning() == running*/ ) {
        //cm.manage();
        //server.executeLoop();
        //yeild server
    }
    
    //clean up Listenermanager    
    
    return 0;
}
