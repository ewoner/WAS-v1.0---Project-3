#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
//#include <unistd.h>

#include "../was_presets.hpp"

int main() {
    int domain = AF_INET, type = SOCK_STREAM, protocol = 0;
    int c = socket( domain, type, protocol );
  
    if ( connect( c, (sockaddr*) &DEFUALT_SERVER, sizeof( DEFUALT_SERVER )) == -1 ) {
        std::cout << "Error" << std::endl;
        return ( errno );
    }
    else {
        std::cout << "It is working!" << std::endl;
    }
    while ( true );
    return 0;
}