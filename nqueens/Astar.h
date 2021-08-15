#ifndef ASTAR_H_
#define ASTAR_H_

#include "Agent.h"
#include "Problem.h"

struct Node {
    Board *board;
    int path_cost;
    int f_score;
    Node *parent;
};

struct CompareNode{
    bool operator()(const Node *n1, const Node *n2){
        if(n1->f_score > n2->f_score){
            return true;
        }

        return false;
    }
};

Result astar_helper(Board *initialState);
bool goalTest(Node *node);
int heuristic(Node *node);
bool isExplored(Node *node, vector<Node *> &exploredSet);
vector<Node *> generateChildren(Node *node);


#endif