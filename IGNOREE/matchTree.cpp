#include <string>
#include <iostream>
#include <vector>
#include "matchTreeRecursive.h"

Node::Node(std::pair<int,int>Match,std::string history){
        this->Match = Match;
}
Node() = default;

Arc::Arc(Node start,Node end,int winner){
    this->start = start;
    this->end = end;
    this->winner = winner;
}
Tree::Tree() = default;



