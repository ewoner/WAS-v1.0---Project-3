#include "chatroom.hpp"
#include "../Account/account.hpp"

ChatRoom::ChatRoom() 
    : ChatRoom( "none" ) {}
ChatRoom::ChatRoom( std::string name ) 
    : ID( 0 ), name( name ), discription( "none" ) {}
int ChatRoom::getID(){
    return this->ID;
}

std::string ChatRoom::getName(){
    return this->name;
}
void ChatRoom::setName( std::string name ){
    this->name = name;
}
std::string ChatRoom::getDiscription(){
    return this->discription;
}
void ChatRoom::setDiscription( std::string discription ){
    this->discription = discription;
}

bool ChatRoom::addAttendee( Account* account ){
    return attendees.insert( account ).second;
}
bool ChatRoom::removeAttendee( Account* account ){
    return ( attendees.erase( account ) == 1 );
}
int ChatRoom::numAttendees(){
    return attendees.size();
}
std::set<Account*>* ChatRoom::getAttendees(){
    std::set<Account*>* accounts = new std::set<Account*>{};
    for ( auto account : this->attendees ) {
        accounts->insert( account );
    }
    return accounts;

}
Account* ChatRoom::seekAttendee( std::string name ){
    for ( auto account : this->attendees ) {
        if ( account->getName() == name ) {
            return account;
        }
    }
    return nullptr;
}

void ChatRoom::load( std::istream is ){
    is >> (*this);
}
void ChatRoom::save( std::ostream os ){
    os << (*this);
}

std::ostream& operator<<( std::ostream& os, const ChatRoom& room ){
    os << "<ChatRoom>\n";
    os << "<Id> " << room.ID << " </Id>\n";
    os << "<Name> " << room.name << " </Name>\n";
    os << "<discription> " << room.discription << " </discription>\n";
    os << "</ChatRoom>\n" << std::flush;
    return os;
}
std::istream& operator>>( std::istream& is, ChatRoom& room ){
    std::string temp;
    is >> temp >> temp >> room.ID;
    is >> temp >> temp >> room.name;
    is >> temp >> temp >> room.discription;
    is >> temp >> temp;
    return is;
}



     //~ int ID
     //~ std::string name
     //~ std::string discription
     //~ std::vector<Account*> attendees
