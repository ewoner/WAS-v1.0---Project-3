#include "account.hpp"

Account::Account() 
    : Account( "none", "none", 0 ) {}
Account::Account( std::string name, std::string password, long loginTime ) 
    : ID( 0 ), name( name ), password( password ), discription( "none" ), loginTime( loginTime )  {}

int Account::getID(){
    return this->ID;
}
void Account::setID( int ID ){
    this->ID = ID;
}

std::string Account::getName(){
    return this->name;
}
void Account::setName( std::string name ){
    this->name = name;
}
std::string Account::getPassword(){
    return this->password;
}
void Account::setPassword( std::string password ){
    this->password = password;
}
std::string Account::getDiscription(){
    return this->discription;
}
void Account::setDiscription( std::string discription ){
    this->discription = discription;
}
long Account::getLoginTime(){
    return this->loginTime;
}
void Account::setLonginTime( long loginTime ) {
    this->loginTime = loginTime;
}
bool Account::addChatRoom( ChatRoom* newRoom ){
    return currentChats.insert( newRoom ).second;
}
bool Account::removeRoom( ChatRoom* removeRoom){
    return ( currentChats.erase( removeRoom ) == 1 );
}
int Account::numChatRooms(){
    return this->currentChats.size();
}
std::set<ChatRoom*>* Account::getChatRooms(){
    std::set<ChatRoom*>* rooms = new std::set<ChatRoom*>{};
    for ( auto room : currentChats ) {
        rooms->insert( room );
    }
    return rooms;
}
ChatRoom* Account::seekChatRoom( std::string name ){
    auto chat = currentChats.begin();
    for ( ; chat != currentChats.end(); chat ++ ) {
        if ( name == (*chat)->getName() ) {
            break;
        }
    }
    return *chat;
}
void Account::load( std::istream& is ){
    is >> (*this);
}
void Account::save( std::ostream& os){
    os << (*this);
}

std::ostream& operator<<( std::ostream& os, const Account& account ) {
    os << "<Account>\n";
    os << "<Id> " << account.ID << " </Id>\n";
    os << "<Name> " << account.name << " </Name>\n";
    os << "<password> " << account.password << " </password>\n";
    os << "<discription> " << account.discription << " </discription>\n";
    os << "/Account>\n" << std::flush;
    return os;
}

std::istream& operator>>( std::istream& is, Account& account ) {
    std::string temp;
    is >> temp >> temp >> account.ID;
    is >> temp >> temp >> account.name;
    is >> temp >> temp >> account.password;
    is >> temp >> temp >> account.discription;
    is >> temp >> temp;
    return is;
}
