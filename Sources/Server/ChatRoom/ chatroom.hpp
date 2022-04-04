#ifndef CHATROOM_HPP
#define CHATROOM_HPP

#include <istream>
#include <ostream>
#include <set>
#include <string>
#include <vector>

class Account;

class ChatRoom {
public:
    ChatRoom();
    
    int getID();
    
    std::string getName();
    void setName( std::string );
    
    std::string getDiscription();
    void setDiscription( std::string );
    
    void addAttendee( Account* );
    void removeAttendee( Account* );
    int numAttendees();
    std::set<Account*> getAttendees();
    Account* seekAttendee( std::string );
    
    void load( std::istream );
    void save( std::ostream );
    
private:
     int ID;
     std::string name;
     std::string discription;
     std::vector<Account*> attendees;
};


#endif
