#include "location.hpp"
#include "../Account/account.hpp"

Location::Location() 
    : Location( "none" ) {}
Location::Location( std::string name ) 
    : ID( 0 ), name( name ), discription( "none" ) {}
int Location::getID(){
    return this->ID;
}

std::string Location::getName(){
    return this->name;
}
void Location::setName( std::string name ){
    this->name = name;
}
std::string Location::getDiscription(){
    return this->discription;
}
void Location::setDiscription( std::string discription ){
    this->discription = discription;
}

bool Location::addAttendee( Account* account ){
    return attendees.insert( account ).second;
}
bool Location::removeAttendee( Account* account ){
    return ( attendees.erase( account ) == 1 );
}
int Location::numAttendees(){
    return attendees.size();
}
std::set<Account*>* Location::getAttendees(){
    std::set<Account*>* accounts = new std::set<Account*>{};
    for ( auto account : this->attendees ) {
        accounts->insert( account );
    }
    return accounts;

}
Account* Location::seekAttendee( std::string name ){
    for ( auto account : this->attendees ) {
        if ( account->getName() == name ) {
            return account;
        }
    }
    return nullptr;
}

void Location::load( std::istream is ){
    is >> (*this);
}
void Location::save( std::ostream os ){
    os << (*this);
}

std::ostream& operator<<( std::ostream& os, const Location& room ){
    os << "<Location>\n";
    os << "<Id> " << room.ID << " </Id>\n";
    os << "<Name> " << room.name << " </Name>\n";
    os << "<discription> " << room.discription << " </discription>\n";
    os << "</Location>\n" << std::flush;
    return os;
}
std::istream& operator>>( std::istream& is, Location& room ){
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
