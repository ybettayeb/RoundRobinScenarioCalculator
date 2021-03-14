#include <string>
#include <iostream>
#include <vector>
#ifndef matchTreeRecursive_h
#define matchTreeRecursive_h

struct Node {
    public:
    std::string history;
    std::pair<int,int> Match;
    Node * left;
    Node * right;
    Node(std::pair<int,int> Match,std::string history);
    Node();

};

#endif