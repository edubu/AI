#ifndef AGENT_H_
#define AGENT_H_

using namespace std;

#include <iostream>
#include <vector>
#include <cmath>
#include "Problem.h"

struct CompareBoardH{
    bool operator()(const Board *b1, const Board *b2){
        if(b1->h_score > b2->h_score)
            return true;
        
        return false;
    }   
};

class Agent {
    public:
        Agent(Board board);

        // Accessible Member functions
        Result hillclimb_sa();
        Result hillclimb_sa(Board *startingState);
        Result hillclimb_fc();
        Result hillclimb_rr();
        Result simulated_annealing(double initialTemp, double decay, double threshold, int numI);
        //Result astar();

    private:
        Board initialState;

};


#endif