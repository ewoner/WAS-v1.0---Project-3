#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <istream>
#include <ostream>
#include <set>
#include <string>

#include "../ChatRoom/chatroom.hpp"

class Account {
public:
    Account();
    
    int getID();
    
    std::string getName();
    void setName( std::string );
    
    std::string getPassword();
    void setPassword( std::string );
    
    std::string getDiscription();
    void setDiscription( std::string );

    long getLoginTime();
    void setLonginTime( long );
    
    bool addChatRoom( ChatRoom* );
    bool removeRoom( ChatRoom* );
    int numChatRooms();
    std::set<ChatRoom*>* getChatRooms();
    ChatRoom* seekChatRoom( std::string );
    
    void load( std::istream& );
    void save( std::ostream& );
    
    friend std::ostream& operator<<( std::ostream&, const Account& );
    friend std::istream& operator>>( std::istream& is, Account& account );
    
private:
     int ID;
     std::string name;
     std::string password;
     std::string discription;
     long loginTime;
     std::set<ChatRoom*> currentChats;
     
     Account( std::string, std::string, long );
     void setID( int );
};


#endif
