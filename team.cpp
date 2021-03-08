#include "team.h"
#include <iostream>
team::team(std::string name)
{
    this->Name = name;
    this->wins = 0;
    this->losses = 0;
    // this->counter++;
}
team::team(std::string name,int wins, int losses,int id){
    this->Name = name;
    this->losses = losses;
    this->wins = wins;
    this->id = id;
    // this->counter++;
}
team::team () = default;



