#ifndef WAS_PRESETS_HPP
#define WAS_PRESETS_HPP

#include <string>

#include <netinet/in.h>
#include <arpa/inet.h>


const int MAX_BUFFER_SIZE = 1024;
const int PORT = 60123;
//const std::string ADDRESS( "127.0.0.1" );
const char * const ADDRESS = "127.0.0.1";

const struct sockaddr_in DEFUALT_SERVER{ AF_INET, PORT, inet_addr( ADDRESS ), "\0" };

#endif
