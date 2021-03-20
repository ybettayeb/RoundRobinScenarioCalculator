#include "team.h"
#include "standings.h"
#include "matchTreeRecursive.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <math.h>
#include <cstdio>
#include <map>

using namespace std;

vector<team> Init(string file)
{
    ifstream fs(file);

    int w, l, id;

    vector<string> row;
    vector<team> Teams;
    std::string line, word;
    id = 0;
    while (std::getline(fs, line))
    {
        row.clear();
        w = 0;
        l = 0;
        stringstream s(line);
        while (getline(s, word, ';'))
        {
            row.push_back(word);
        }
        w = stoi(row[1]);
        l = stoi(row[2]);
        team tmp;
        tmp = team(row[0], w, l, id);
        Teams.push_back(tmp);
        id++;
    }
    return Teams;
}
Node *newNode(std::pair<int, int> Match, int winner, int looser)
{
    Node *node = new Node;
    node->Match = Match;
    node->winner = winner;
    node->looser = looser;
    node->left = node->right = NULL;
    return (node);
}

Node *insertLevelOrder(vector<int> inOrder, vector<pair<int, int>> matches, Node *root, int i, int n, int win, int &cpt)
{

    int winner = 0;
    int looser =0;

    if (i < n)
    {
        if (win == 1)
        {

            winner = matches[inOrder[i]].first;
            looser = matches[inOrder[i]].second;
        }
        else
        {
            winner = matches[inOrder[i]].second;
            looser = matches[inOrder[i]].first;
        }

        Node *temp = newNode(matches[inOrder[i]], winner,looser);
        root = temp;
        cout << "call number " << cpt << endl;
        cpt++;

        //left child
        temp->left = insertLevelOrder(inOrder, matches, root->left, 2 * i + 1, n, 1, cpt);

        // right Child
        temp->right = insertLevelOrder(inOrder, matches, root->right, 2 * i + 2, n, 2, cpt);
    }
    return root;
}

void calcMatchPlanning(vector<team> teams, vector<vector<pair<int, int>>> &matches)
{

    size_t const roundNumbers = (teams.size() - 1) * 2;
    size_t const matchNumbers = (teams.size() / 2); // Match per round since 1 match => 2 teams
    size_t const nbTeams = teams.size();
    matches.resize(roundNumbers);
    for (int i = 0; i < roundNumbers; i++)
    {
        matches[i].resize(matchNumbers);
    }
    // pair<int, int> **matches[roundNumbers][matchNumbers];
    for (int round = 0; round < roundNumbers; round++)
    {
        for (int match = 0; match < matchNumbers; match++)
        {
            int home = (round + match) % (nbTeams - 1);
            int away = (nbTeams - 1 - match + round) % (nbTeams - 1);
            if (match == 0)
            {
                away = nbTeams - 1;
            }
            matches[round][match] = make_pair(home, away);
        }
    }
}
void vectorToArr(vector<vector<pair<int, int>>> &matches, vector<pair<int, int>> &matches1d)
{
    size_t const roundNumbers = matches.size();
    size_t const matchNumbers = matches[0].size(); // Match per round since
    for (int i = 0; i < roundNumbers; i++)
    {
        for (int j = 0; j < matchNumbers; j++)
        {
            matches1d.push_back(matches[i][j]);
        }
    }
}
standings updateStandings(vector<pair<int,int>> path, vector<team> Teams){
    for (pair<int,int> match : path){
        Teams[match.first].wins += 1;
        Teams[match.second].losses += 1;
    }
    return standings(Teams);
}
std::vector<int> InOrderTree(std::vector<std::pair<int, int>> matches)
{
    std::vector<int> treeTraversalInOrder;
    for (int i = 0; i < matches.size(); i++)
    {
        for (int j = 0; j < pow(2, i); j++)
        {
            treeTraversalInOrder.push_back(i);
        }
    }
    return treeTraversalInOrder;
}

unsigned int getLeafCount(Node *node)
{
    if (node == NULL)
        return 0;                                  //base recursion case
    if (node->left == NULL && node->right == NULL) // leaf case
        return 1;
    else
        return getLeafCount(node->left) + //recursive call
               getLeafCount(node->right);
}

void printAllPaths(Node *node, vector<pair<int,int>> &path, vector<vector<pair<int,int>>> &paths)
{

    if (node == NULL)
    {
        return;
    }
    path.push_back(make_pair(node->winner,node->looser));
    if (node->left == NULL && node->right == NULL)
    { //if we're on a leaf
        vector<pair<int,int>> curr;
        for (pair<int,int> data : path)
        {
            curr.push_back(data);
            // cout << data.first << " " ;
        }
        paths.push_back(curr);
        cout << endl;
    }
    printAllPaths(node->left, path, paths);
    printAllPaths(node->right, path, paths);

    path.pop_back(); // we remove the node since we're gonna branch of that 
}
void printOddsOfMakingItToPlayoffs(int cutoff,vector<standings> outcomes){
    int count;
    map <string,double> m;
    int counts[outcomes[0].teams.size()] = {};

    for(standings scenario: outcomes){
        for(int i = 0; i < cutoff; i++){
            counts[scenario.teams[i].id]++;
        }      
    }
    for (int i = 0; i < outcomes[0].teams.size(); i++){
    m[outcomes[0].teams[i].getName()] = counts[outcomes[0].teams[i].id]/outcomes.size();
    cout << outcomes[0].teams[i].getName() << "'s of making it to top" << to_string(cutoff) << "are: " << to_string(m[outcomes[0].teams[i].getName()]) << endl;
    }

}
int main(int argc, char *argv[])
{

    vector<team> Teams;
    Teams = Init(argv[1]); // initializing the team array
    vector<vector<pair<int, int>>> matches;
    vector<pair<int, int>> MatchesArr;
    vector<int> InOrderTraversal;
    int MatchesPlayed = (Teams[0].getLosses() + Teams[0].getWins()) * (Teams.size() / 2); // we'll want to slice our array so we dont consider already played matches
    standings std = standings(Teams);
    vector<pair<int, int>> slicedMatches;

    // the main needs HUGE refactoring but kinda too lazy to do it RN, will do tomorrow <- blatant lie from me from 2 days ago
    calcMatchPlanning(Teams, matches);
    vectorToArr(matches, MatchesArr);

    slicedMatches = vector<pair<int, int>>(MatchesArr.begin() + MatchesPlayed, MatchesArr.end()); // copy constructor
    InOrderTraversal = InOrderTree(slicedMatches);
    int n = InOrderTraversal.size();
    int cpt = 0;
    Node *root = insertLevelOrder(InOrderTraversal, MatchesArr, root, 0, n, 1, cpt);

    vector<pair<int,int>> paths;
    vector<vector<pair<int,int>>> actualPaths;
    vector<standings> outcomes;
    // freopen("output.txt", "w",stdout);

    printAllPaths(root, paths,actualPaths);

    for (vector<pair<int,int>> path : actualPaths){
        outcomes.push_back(updateStandings(path,Teams)); 
    }
    printOddsOfMakingItToPlayoffs(6,outcomes);
    // fclose(stdout);

    return 0;
}
