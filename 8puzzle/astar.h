#ifndef ASTAR_H_
#define ASTAR_H_

#include <queue>
#include <vector>
#include <iostream>
#include "puzzle.h"
#include "problem.h"

using namespace std;

struct comparePuzzle
{
    bool operator()(Puzzle *p1, Puzzle *p2)
    {
        if(p1->f_score > p2->f_score)
            return true;
        
        return false;
    }
};

class AStar
{
    public:
        // member variables
        priority_queue<Puzzle *, vector<Puzzle *>, comparePuzzle> frontier;
        vector<char> solution_seq;
        vector<vector<int> > exploredSet;
        Puzzle initial_state;

        // member functions
        AStar(){}
        void insertFrontier(Puzzle *a_node);
        Puzzle * popFrontier();
        bool isExplored(vector<int> &state);
        void insertExplored(vector<int> state);
        vector<char> astar(Puzzle initial_node);
        vector<char> backtrack(Puzzle *endNode);

};


#endif