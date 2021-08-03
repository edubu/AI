#include <iostream>
#include "puzzle.h"
#include "astar.h"

using namespace std;

int main(int argc, char **argv)
{
    Puzzle initial;
    int pos;

    cout << "Input 9 numbers of 0-8 for matrix" << endl;
    for(int i = 0; i < 9; ++i)
    {
        cin >> pos;
        initial.state[i] = pos;
    }
    AStar as;
    vector<char> solution = as.astar(initial);

    for(int i = 0; i < solution.size(); i++){
        cout << solution[i] << " ";
    }

    return 0;
}