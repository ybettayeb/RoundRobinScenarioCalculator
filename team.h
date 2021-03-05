#include <string>
#include <iostream>
#ifndef team_h
#define team_h
class team
{
protected:
    std::string Name;
    int wins;
    int losses;
public:
    team(std::string name);
    team(std::string name,int wins, int losses);
    team();
    std::string getName(){
        return this->Name;
    }
    bool operator>(team& t2){
        return this->wins > t2.wins;
    }
    int getWins(){
        return this->wins;
    }
    int getLosses(){
        return this->losses;
    }
    std::ostream &write(std::ostream &dest) const { 
        return dest << this->Name << " "<<this->wins << " - " << this->losses;
    }

friend std::ostream &operator<<(std::ostream &os, team const &t) 
{ 
return t.write(os);
}
};




#endif