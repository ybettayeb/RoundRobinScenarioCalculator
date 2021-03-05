#include "team.h"
#include <iostream>
team::team(std::string name)
{
    this->Name = name;
    this->wins = 0;
    this->losses = 0;
}
team::team(std::string name,int wins, int losses){
    this->Name = name;
    this->losses = losses;
    this->wins = wins;
}
team::team () = default;



