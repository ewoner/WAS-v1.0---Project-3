#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <unistd.h>

#include "../was_presets.hpp"

#include "connection.hpp"
#include "Handlers/imp_handlers.hpp"

//for testing only
#define _STDOUT 1
#define _STDIN 0
#define _ROOT_DIR "./"

void error( std::string, int err = 1 );
int main() {
    Connection con;
    logon_handler lh( &con);
    con.addHandler( lh );
    return 0;
}

int main1() {
    std::cout << "Hello World!\n";
    int domain = AF_INET, type = SOCK_STREAM, protocol = 0;
    int s = socket( domain, type, protocol );
    std::cout << "Binding to: " << inet_ntoa( DEFUALT_SERVER.sin_addr ) << " port: " 
        << DEFUALT_SERVER.sin_port << std::endl;
    if ( bind ( s, ( struct sockaddr* ) &DEFUALT_SERVER, sizeof( DEFUALT_SERVER ) ) == -1 ) {
        error("Unable to bind to Port " + std::to_string( PORT ) );
    }
    if ( listen( s, 1 ) == -1 ) {
        error( "Error trying to begin listening on port " + std::to_string( PORT ) );
    }
    struct sockaddr * cli_addr;
    int * cli_addr_len = new int{0};
    int c = 0;
    while ( true )  {
        struct sockaddr_in cli_addr;
        socklen_t  clilen;
        clilen = sizeof (cli_addr);
         c = accept (s, (struct sockaddr * ) &cli_addr, &clilen);
        
        std::cout << "Connection received from: " << inet_ntoa( cli_addr.sin_addr ) << " port: " 
        << cli_addr.sin_port << std::endl;
    }
}

void error( std::string errMsg, int err ) {
    std::cerr << "Program terminating due to error: " << errMsg << std::endl;
    exit( errno != 0 ? errno : err != 0 ? err : 1 );
}