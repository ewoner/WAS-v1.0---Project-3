#ifndef CHATROOM_HPP
#define CHATROOM_HPP

#include <istream>
#include <ostream>
#include <set>
#include <string>

class Account;

class ChatRoom {
public:
    ChatRoom();
    
    int getID();
    
    std::string getName();
    void setName( std::string );
    
    std::string getDiscription();
    void setDiscription( std::string );
    
    bool addAttendee( Account* );
    bool removeAttendee( Account* );
    int numAttendees();
    std::set<Account*>* getAttendees();
    Account* seekAttendee( std::string );
    
    void load( std::istream );
    void save( std::ostream );
    
    friend std::ostream& operator<<( std::ostream&, const ChatRoom& );
    friend std::istream& operator>>( std::istream&, ChatRoom& );
    
private:
     int ID;
     std::string name;
     std::string discription;
     std::set<Account*> attendees;
     
     ChatRoom( std::string );
};
#endif
