#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <istream>
#include <ostream>
#include <set>
#include <string>

#include "../Location/location.hpp"

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
    
    bool addLocation( Location* );
    bool removeRoom( Location* );
    int numLocations();
    std::set<Location*>* getLocations();
    Location* seekLocation( std::string );
    
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
     std::set<Location*> currentChats;
     
     Account( std::string, std::string, long );
     void setID( int );
};


#endif
