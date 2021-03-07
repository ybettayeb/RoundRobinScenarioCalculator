#include "team.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "standings.h"

standings::standings(std::vector<team> tms){
    std::sort(tms.begin(),tms.end());
    std::reverse(tms.begin(),tms.end()); // sub optimal, needs to definie custom comparator for the sorting
    this->teams = tms;
}