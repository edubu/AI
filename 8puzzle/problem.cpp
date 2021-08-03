#include "problem.h"
#include "puzzle.h"
#include <iostream>

using namespace std;

vector<int> goal_state = {0, 1, 2, 3, 4, 5, 6, 7, 8};


int goalTest(Puzzle * curr_node)
{
    for(int i = 0; i < 9; ++i)
    {
        if(curr_node->state[i] != goal_state[i])
            return 0;
    }

    return 1;
}

// Summation of manhattan distance of each spot from where it should be
int heuristic(Puzzle * curr_node){
    int totalDistance = 0;
    for(int i = 0; i < 9; i++){
        int goalIndex;
        for(int j = 0; j < 9; j++){
            if(goal_state[j] == curr_node->state[i])
            {
                goalIndex = j;
                break;
            }
        }

        int currCol = i % 3;
        int currRow = (i - currCol) / 3;
        int goalCol = goalIndex % 3;
        int goalRow = (goalIndex - goalCol) / 3;

        totalDistance += (abs(currCol - goalCol) + abs(currRow - goalRow));
    }

    return totalDistance;
}

Puzzle * transition(Puzzle *curr_node, int action)
{
    Puzzle *next_node = new Puzzle;

    int blank_pos = curr_node->state[0];
    int tile;

    if(action == 1) // UP
    {
        tile = blank_pos - 3;
        for(int i = 0; i < 9; i++){
            if(curr_node->state[i] == tile)
            {
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = curr_node->state[i];
            }
        }

        next_node->action = 1;
    }
    else if(action == 2) // LEFT
    {
        tile = blank_pos - 1;
        for(int i = 0; i < 9; i++){
            if(curr_node->state[i] == tile)
 
            {    
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = curr_node->state[i];
            }
        }

        next_node->action = 2;
    }
    else if(action == 4) // DOWN
    {
        tile = blank_pos + 3;
        for(int i = 0; i < 9; i++){
            if(curr_node->state[i] == tile)
 
            {    
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = curr_node->state[i];
            }
        }

        next_node->action = 4;
    }
    else { // RIGHT
        tile = blank_pos + 1;
        for(int i = 0; i < 9; i++){
            if(curr_node->state[i] == tile)
 
            {    
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = curr_node->state[i];
            }
        }

        next_node->action = 8;
    }

    next_node->parent = curr_node;
    next_node->path_cost = curr_node->path_cost + 1;
    next_node->f_score = next_node->path_cost + heuristic(next_node);

    return next_node;
}

vector<Puzzle *> generateChildren(Puzzle *curr_node)
{
    vector<Puzzle *> children;
    int blank_pos = curr_node->state[0];
    int col = blank_pos % 3;
    int row = (blank_pos - col) / 3;

    if(col > 0)
       children.push_back(transition(curr_node, 2)); 

    if(col < 2)
        children.push_back(transition(curr_node, 8));
    if(row > 0)
        children.push_back(transition(curr_node, 1));
    if(row < 2)
        children.push_back(transition(curr_node, 4));
    
    return children;
}