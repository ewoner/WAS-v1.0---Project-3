#ifndef IMP_HANDLER_HPP
#define IMP_HANDLER_HPP

#include <string>

#include "handler.hpp"

class logon_handler : public Handler {
public:
    logon_handler(Connection*);
    void enter() override;
    void handle(std::string) override;
    void printmenu();
private:
    //empty
};

#endif