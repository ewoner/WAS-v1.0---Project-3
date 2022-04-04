#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <istream>
#include <ostream>
#include <set>
#include <string>
#include <vector>

class ChatRoom;

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
    
    void addChatRoom( ChatRoom* );
    void removeRoom( ChatRoom* );
    int numChatRooms();
    std::set<ChatRoom*> getChatRooms();
    ChatRoom* seekChatRoom( std::string );
    
    void load( std::istream );
    void save( std::ostream );

private:
     int ID;
     std::string name;
     std::string password;
     std::string discription;
     long loginTime;
     std::vector<ChatRoom*> currentChats;
     
     Account( std::string, std::string, long );
};


#endif
