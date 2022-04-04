#ifndef LOGONHANDLER_HPP
#define LOGONHANDLER_HPP

#include <string>

#include "../Account/account.hpp"
#include "handler.hpp"

enum class LogonState  { EnterName, EnterPass, EnterNewName, EnterNewPass, DeadState };



class LogonHandler : public Handler{
public:
    LogonHandler();
    LogonHandler( Connection * );

    virtual void leave();
    virtual void enter();
    virtual void handle( std::string data );
    
    void gotoMenu();

private:
    const std::string loginDataFile;
    const std::string newAccountDataFile;
    LogonState  logonState;
    int badAttempts;
    std::string name;
    std::string pass;
    Account account;

};

#endif
