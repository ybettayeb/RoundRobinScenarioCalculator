#include <string>
#include <iostream>
#include <vector>
#include "team.h"
#ifndef standings_h
#define standings_h

class standings{

protected:
    
public:
    standings(std::vector<team> teams);
    std::vector<team> teams;
    friend bool operator==(const standings &s1, const standings &s2){
    return s1.teams == s2.teams;
    }
};


#endif