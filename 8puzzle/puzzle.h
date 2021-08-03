#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <vector>

using namespace std;

class Puzzle
{
    public:
        // member data
        vector<int> state;
        int path_cost;
        int f_score;
        Puzzle * parent;
        int action;

        //member functions
        Puzzle(); // constructor
};


#endif