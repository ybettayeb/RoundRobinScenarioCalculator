#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include "matchTreeRecursive.h"


// class Tree{
//     public:
//     std::vector<Node> Nodes;
//     // std::vector<Arc> Arcs;
//     Tree::Tree(std::vector<Node> Matches);

// };
// class Arc {
//     public:
//     Node start;
//     Node end;
//     int winner;
//     Arc::Arc(Node::Node start,Node::Node end, int winner);
// };
Node::Node(std::pair<int,int>Match, std::string history){
        this->Match = Match;
        this->left = nullptr;
        this->right = nullptr;
        this->history += history;
}
Node::Node() = default;
// Arc::Arc(Node::Node start,Node::Node end,int winner){
//     this->start = start;
//     this->end = end;
//     this->winner = winner;

// } 

// Node generateTree(int depth,){
//     if(depth<0) return;

// }
// void generateTree(Tree tree, std::vector<std::pair<int,int>> matches){
//     std::vector<Node> Nodes;
//     std::vector<Arc> Arcs;
//     for (std::pair<int,int> match : matches){
//         Nodes.push_back(Node(match)); // List of nodes
//     }
//     for (int i = 0; i <Nodes.size()-2;i++){
//         Arcs.push_back(Arc(Nodes[i],Nodes[i+1],Nodes[i].Match.first));
//         Arcs.push_back(Arc(Nodes[i],Nodes[i+1],Nodes[i].Match.second));
//     }
//     tree.Arcs = Arcs;
//     tree.Nodes = Nodes;
//     }

