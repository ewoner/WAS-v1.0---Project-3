#ifndef MENUHANDLER_HPP
#define MENUHANDLER_HPP

#include <string>

#include "../Account/account.hpp"
#include "handler.hpp"




class MenuHandler : public Handler{
public:
    MenuHandler();
    MenuHandler( Connection * );

    virtual void leave();
    virtual void enter();
    virtual void handle( std::string data );
    virtual void printMenu();
    void gotoMenu();

private:
    const std::string helpFile;
    int badAttempts;
    std::string name;
    std::string pass;
    Account account;

};

#endif
