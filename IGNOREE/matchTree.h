#include <string>
#include <iostream>
#include <vector>
#ifndef matchTree_h
#define matchTree_h

class Node {
    public:
    std::pair<int,int> Match;
    // Node::Node * left;
    // Node::Node * right;
    Node(std::pair<int,int> Match);
    Node();

};
class Arc {
    public:
    Node start;
    Node end;
    int winner;
    Arc(Node start,Node end, int winner);
};

class Tree{
    public:
    std::vector<Node> Nodes;
    std::vector<Arc> Arcs;
    Tree(std::vector<Node> Matches, std::vector<Arc> Outcomes);
    Tree();

};
// void generateTree(Tree tree, std::vector<std::pair<int,int>> matches);
// void printTree(Tree tree);
#endif