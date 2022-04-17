#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <istream>
#include <ostream>
#include <set>
#include <string>

class Account;

class Location {
public:
    Location();
    
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
    
    friend std::ostream& operator<<( std::ostream&, const Location& );
    friend std::istream& operator>>( std::istream&, Location& );
    
private:
     int ID;
     std::string name;
     std::string discription;
     std::set<Account*> attendees;
     
     Location( std::string );
};
#endif
