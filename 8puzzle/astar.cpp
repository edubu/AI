#include <cmath>
#include <iostream>
#include <cstddef>
#include "puzzle.h"
#include "problem.h"
#include "astar.h"
#include <cstdlib>
#include <algorithm>
using namespace std;

void AStar::insertFrontier(Puzzle *a_node){
    frontier.push(a_node);
}

Puzzle * AStar::popFrontier()
{
    Puzzle * top = frontier.top();
    frontier.pop();
    return top;
}

void AStar::insertExplored(vector<int> state)
{
    exploredSet.push_back(state);
}

bool AStar::isExplored(vector<int> &state)
{
    for(int i = 0; i < exploredSet.size(); i++){
        if(state == exploredSet[i])
            return true;
    }

    return false;
}

vector<char> AStar::astar(Puzzle initial_node)
{

    initial_state = initial_node;
    Puzzle *init_node = &initial_node;

    if(goalTest(init_node)){
        return {};
    }

    frontier.push(init_node);

    bool hasFoundSolution = false;
    while(!frontier.empty() && !hasFoundSolution)
    {
        Puzzle *currNode = frontier.top();
        frontier.pop();
        insertExplored(currNode->state);

        vector<Puzzle *> children = generateChildren(currNode);

        // Check to see if children are goal state
        // Check to see if children are already explored -- if not, add to frontier
        for(int i = 0; i < children.size(); i++)
        {
            if(goalTest(children[i])){
                return backtrack(children[i]);
            }

            if(!isExplored(children[i]->state))
                insertFrontier(children[i]);
        }
    }

    return {};
}

vector<char> AStar::backtrack(Puzzle *endNode)
{
    vector<char> seq;
    Puzzle *currNode = endNode;
    while(currNode->parent != nullptr)
    {
        switch(currNode->action)
        {
            case 1:
                seq.push_back('U');
                break;
            case 2:
                seq.push_back('L');
                break;
            case 4:
                seq.push_back('D');
                break;
            case 8:
                seq.push_back('R');
                break;
        }

        currNode = currNode->parent;
    }

    reverse(seq.begin(), seq.end());
    cout << "Total steps: " << endNode->path_cost + 1 << endl;
    return seq; 
}