#include <queue>
#include <vector>
#include <iostream>
#include <cassert>
#include <chrono>
#include <algorithm>
#include "Astar.h"

using namespace std;
using namespace std::chrono;

Result astar_helper(Board *initialState){
    // Start Timer
    auto start = high_resolution_clock::now();

    Result result;
    result.method = "A*";


    // Create initialNode
    Node *initialNode = new Node;
    initialNode->board = initialState;
    initialNode->path_cost = 0;
    initialNode->parent = nullptr;
    initialNode->f_score = initialNode->path_cost + heuristic(initialNode);

    vector<Node *> exploredSet;
    priority_queue<Node *, vector<Node *>, CompareNode> pq;

    // Push initialNode into pq
    pq.push(initialNode);
    exploredSet.push_back(initialNode);

    // Start searching
    bool hasFound = false;
    Node *lastNode = nullptr;
    while(!pq.empty() && !hasFound){
        Node *currNode = pq.top();
        pq.pop();

        vector<Node *> children = generateChildren(currNode);

        // Check children
        for(int i = 0; i < children.size(); i++){
            if(goalTest(children[i])){
                lastNode = children[i];
                hasFound = true;
                break;
            }
            
            if(!isExplored(children[i], exploredSet)){
                pq.push(children[i]);
                exploredSet.push_back(children[i]);
            }
            else {
                delete children[i];
            }
        }
    }

    if(lastNode != nullptr)
        result.solved = 1;
    else
        result.solved = 0;

    // Clean up memory
    for(int i = 0; i < exploredSet.size(); ++i){
        delete exploredSet[i];
    }

    // End timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    result.exec_time = (double)duration.count() / 1000.0;

    return result;
}

bool goalTest(Node *node){
    if(heuristic(node) == 0)
        return true;
    return false;
}

int heuristic(Node *node){
    return node->board->h_score;
}

vector<Node *> generateChildren(Node *node){
    // Create new board for each position queen in column can go to
    vector<Node *> children;

    for(int i = 0; i < node->board->board_size; ++i){
        // find queen row
        int qRow;
        for(int j = 0; j < node->board->board_size; ++j){
            if(node->board->state[j][i]){
                qRow = j;
                break;
            }
        }// Itr through rows

        // Create new states for each non queen space in column by swapping
        for(int j = 0; j < node->board->board_size; ++j){
            if(j != qRow){
                Board *newBoard = new Board;
                newBoard->board_size = node->board->board_size;
                newBoard->state = node->board->state;
                newBoard->state[j][i] = 1;
                newBoard->state[qRow][i] = 0;
                newBoard->h_score = heuristic(newBoard);
                Node *newNode = new Node;
                newNode->parent = node;
                newNode->board = newBoard;
                newNode->path_cost = node->path_cost + 1;
                newNode->f_score = newNode->path_cost + newNode->board->h_score;

                children.push_back(newNode);
            }
        }
    } // Itr through columns

    return children;
}

bool isExplored(Node *node, vector<Node *> &exploredSet){
    for(int i = 0; i < exploredSet.size(); ++i){
        if(exploredSet[i] == node)
            return true;
    }

    return false;
}
