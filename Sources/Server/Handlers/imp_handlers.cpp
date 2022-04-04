#include "imp_handlers.hpp"

logon_handler::logon_handler(Connection * con) : Handler( con ) {}
void logon_handler::enter() {
    printmenu();
}

void logon_handler::handle(std::string data){
    
}
#include <iostream>
void logon_handler::printmenu() {
    std::cout << "test";
    std::cout << "\f";
    std::cout << "end" << std::endl;
    
}