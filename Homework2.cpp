// Homework2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct player{
    string name;
    string position;
    int yards;
};

void readPlayerStats(player (&playerList)[11])
{
    string line;
    ifstream file("nfl_team.txt");
    for (int i = 0; i < 11; i++)
    {
        if (file.is_open())
        {
            while (getline(file, line))
            {
                //cout << "Name of player " << "is : " << playerList[i].name << endl;
                istringstream ss(line);
                //cout << line << endl;
                //printf("Size of arr[] in func(): %d bytes",
                //sizeof(playerList));
                ss >> playerList[i].name >> playerList[i].position >> playerList[i].yards;
                //cout << line << endl;
                //cout << "Name is then: " << playerList[i].name << endl;
                //cout << "Position is " << playerList[i].position << endl;
                //cout << "Yards they have is " << playerList[i].yards << endl;
                i++;
            }
            
        }
        else
        {
            cout << "Can't find file";
        }
        file.close();
    }
    
}

int calculateTotalYards(player playerList[11])
{
    int yardSum = 0;
    for (int i = 0; i < 11; i++)
    {
        cout << "This player has name:" << playerList[i].name << endl;
        cout << "This player has position:" << playerList[i].position << endl;
        cout << "This player has yards: " << playerList[i].yards << endl << endl;
        yardSum += playerList[i].yards;
        //cout << "Current Yard Sum is " << yardSum << endl;
    }
    return yardSum;
}

int main()
{
    player Players[11];
    readPlayerStats(Players);
    for (int i = 0; i < 11; i++)
    {
        //cout << "name: " << Players[i].name << endl;
        //cout << "position: " << Players[i].position << endl;
        //cout << "yards: " << Players[i].yards << endl << endl;
    }
    cout << "The yard sum is " << calculateTotalYards(Players);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
