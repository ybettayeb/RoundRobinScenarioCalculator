#include "team.h"
#include "standings.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<team> Init()
{
    ifstream fs("teams.csv");

    int w, l,id;

    vector<string> row;
    vector<team> Teams;
    std::string line, word;
    id =0;
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
        tmp = team(row[0], w, l,id);
        Teams.push_back(tmp);
        id++;
    }
    return Teams;
}

// std::pair<vector<team>,vector<team>> roundRobin(vector<team> Teams)
// {
//     size_t const half_size = Teams.size() / 2;
//     double matches = (Teams.size() * (Teams.size() - 1)) / 2; // matches = n(n-1)/2
//     vector<team> firstHalf, secondHalf;
    
//     vector<team> split_lo(Teams.begin(), Teams.begin() + half_size);
//     vector<team> split_hi(Teams.begin() + half_size, Teams.end());

//     return std::make_pair(split_hi,split_lo);
// }

void calcMatchPlanning(vector<team> teams,vector<vector<pair<int,int>>> &matches)
{
    
    size_t const roundNumbers = (teams.size() - 1) * 2;
    size_t const matchNumbers = (teams.size() / 2); // Match per round since 
    size_t const nbTeams = teams.size();
    matches.resize(roundNumbers);
    for (int i = 0; i<roundNumbers;i++){
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
// pair<int,int> **calcMatchPlanning(vector<team> teams,matches)
// {

//     size_t const roundNumbers = (teams.size() - 1) * 2;
//     size_t const matchNumbers = (teams.size() / 2); // Match per round since 
//     size_t const nbTeams = teams.size();

//     pair<int,int> matches [roundNumbers][matchNumbers];
//     // pair<int, int> **matches[roundNumbers][matchNumbers];
//     for (int round = 0; round < roundNumbers; round++)
//     {
//         for (int match = 0; match < matchNumbers; match++)
//         {
//             int home = (round + match) % (nbTeams - 1);
//             int away = (nbTeams - 1 - match + round) % (nbTeams - 1);
//             if (match == 0)
//             {
//                 away = nbTeams - 1;
//             }
//             matches[round][match] = make_pair(home, away);
//         }
//     }
//     return matches;
// }

int main(int argc, char *argv[])
{

    // Liste des teams : GO;GW;IZI;KC;LDLC;MSFP;SOLARY;BDS;MCES;VITB
    vector<team> Teams;
    Teams = Init();
    vector<vector<pair<int,int>>> matches;
    standings std = standings(Teams);
    // calcMatchPlanning(Teams,matches);


    // for (int i = 0; i < matches.size(); i++)
    // {
    //     cout << "round " << i << endl;
    //     for (int j = 0; j<matches[0].size();j++){ // every round is the same length 
    //         cout << "team " << matches[i][j].first << " plays against " << matches[i][j].second << endl;
    //     }
    // }
    int test;
}

