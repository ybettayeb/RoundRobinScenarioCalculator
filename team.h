#include <string>
#include <iostream>
#ifndef team_h
#define team_h
class team
{
    // static int counter;
protected:
    std::string Name;

   

public:
    int id;
    int wins;
    int losses;
    team(std::string name);
    team(std::string name, int wins, int losses, int id);
    team();
    std::string getName()
    {
        return this->Name;
    }
    bool operator>(team &t2)
    {
        return this->wins > t2.wins;
    }
    int getWins()
    {
        return this->wins;
    }
    int getLosses()
    {
        return this->losses;
    }
    std::ostream &write(std::ostream &dest) const
    {
        return dest << this->Name << " " << this->wins << " - " << this->losses;
    }
    // bool operator>(const team &t2)
    // {
    //     return wins > t2.wins;
    // }

    // bool operator==(const team &t2)
    // {
    //     return wins == t2.wins;
    // }
    // bool operator>=(const team &t2){
    //     return wins >= t2.wins;
    // }
    // bool operator<=(const team &t2){
    //     return wins <= t2.wins;
    // }
    // bool operator!=(const team &t2){
    //     return wins != t2.wins;
    // }

    friend std::ostream &operator<<(std::ostream &os, team const &t)
    {
        return t.write(os);
    }
    friend bool operator<(const team &t1,const team &t2)
    {
        return t1.wins < t2.wins;
    }
        friend bool operator>(const team &t1,const team &t2)
    {
        return t1.wins > t2.wins;
    }
    friend bool operator==(const team &t1, const team &t2){
        return t1.Name == t2.Name;
    }
};
   
#endif