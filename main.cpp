#include "team.h"
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

    int w, l;

    vector<string> row;
    vector<team> Teams;
    std::string line, word;

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
        tmp = team(row[0], w, l);
        Teams.push_back(tmp);
    }
    return Teams;
}

void roundRobin(vector<team> Teams){
    int competitors = Teams.size();
    double matches = (competitors * (competitors-1))/2;
    vector<team> firstHalf,secondHalf;
    for (int i=0;i <= competitors/2; i++){
        firstHalf.push_back(Teams[i]);
        secondHalf.push_back(Teams[competitors-i]);
    }
    for(int i = 0; i < Teams.size()/2;i++){
        cout << firstHalf[i] << endl << secondHalf[i];
    }
}

int main(int argc, char *argv[])
{

    // Liste des teams : GO;GW;IZI;KC;LDLC;MSFP;SOLARY;BDS;MCES;VITB
    vector<team> Teams;
    Teams = Init();
    // for (int i = 0; i < Teams.size(); i++)
    // {
    //     cout << Teams[i] << endl;
    // }
    roundRobin(Teams);
}

