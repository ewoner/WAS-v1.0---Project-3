#include "./ListenManager/listenmanager.hpp"
#include <unistd.h>
#include <iostream>
#include <thread>

void test() {}
int main( int nargs, char ** args ) {
    ConnectionManager * cm = new ConnectionManager;
    ListenManager * lm = new ListenManager;
    lm->init ( cm );
    std::thread t( &ListenManager::start, lm );
    
    //Parse Command line arguements
    
    
    //main loop
    while ( true /*server.isRunning() == running*/ ) {
        //cm.manage();
        //server.executeLoop();
        //yeild server
    }
    
    //clean up Listenermanager    
    
    return 0;
}
