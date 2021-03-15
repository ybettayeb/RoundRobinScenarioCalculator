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

using namespace std;

vector<team> Init()
{
    ifstream fs("teams.csv");

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
Node *newNode(std::pair<int, int> Match, std::string history)
{
    Node *node = new Node;
    node->Match = Match;
    node->history = history;
    node->left = node->right = NULL;
    return (node);
}

Node *insertLevelOrder(vector<int> inOrder, vector<pair<int, int>> matches, Node *root, int i, int n, int win, int &cpt)
{

    string winner = "";

    if (i < n)
    {
        if (win == 1)
        {

            winner = to_string(matches[inOrder[i]].first);
        }
        else
            winner = to_string(matches[inOrder[i]].second);
        Node *temp = newNode(matches[inOrder[i]], winner);
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
            int home = (round + match) % (nbTeams - 1); // #1st team plays last 2nd team plays against before last so on so forth 
            int away = (nbTeams - 1 - match + round) % (nbTeams - 1); // we're thus, congruent to the nb teams -1, except the first team that will never move 
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

void printAllPaths(Node *node, vector<int> &path)
{

    if (node == NULL)
    {
        return;
    }
    path.push_back(stoi(node->history));
    if (node->left == NULL && node->right == NULL)
    { //if we're on a leaf
        for (int data : path)
        {

            cout << data << " ";
        }
        cout << endl;
    }
    printAllPaths(node->left, path);
    printAllPaths(node->right, path);

    path.pop_back(); // we remove the path since we just updated it with a longer one
}

int main(int argc, char *argv[])
{

    vector<team> Teams;
    Teams = Init(); // initializing the team array
    vector<vector<pair<int, int>>> matches;
    vector<pair<int, int>> MatchesArr;
    vector<int> InOrderTraversal;
    int MatchesPlayed = (Teams[0].getLosses() + Teams[0].getWins()) * (Teams.size() / 2); // we'll want to slice our array so we dont consider already played matches
    standings std = standings(Teams);
    vector<pair<int, int>> slicedMatches;

    // the main needs HUGE refactoring but kinda too lazy to do it RN, will do tomorrow
    calcMatchPlanning(Teams, matches);
    vectorToArr(matches, MatchesArr);

    slicedMatches = vector<pair<int, int>>(MatchesArr.begin() + MatchesPlayed, MatchesArr.end()); // copy constructor
    InOrderTraversal = InOrderTree(slicedMatches);
    int n = InOrderTraversal.size();
    int cpt = 0;
    Node *root = insertLevelOrder(InOrderTraversal, MatchesArr, root, 0, n, 1, cpt);

    vector<int> paths;
    freopen("output.txt", "w", stdout);
    printAllPaths(root, paths);
    fclose(stdout);
}
