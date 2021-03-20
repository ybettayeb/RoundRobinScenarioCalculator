#include <string>
#include <iostream>
#include <vector>
#ifndef matchTreeRecursive_h
#define matchTreeRecursive_h

struct Node {
    public:
    int winner,looser;
    std::pair<int,int> Match;
    Node * left;
    Node * right;
    // Node(std::pair<int,int> Match);
    Node();

};

#endif