#ifndef PROBLEM_H_
#define PROBLEM_H_

using namespace std;

#include <string>
#include <iostream>
#include <vector>

struct Result {
    string method;
    double exec_time;
    int solved;
};

struct Board {
    int board_size;
    vector<vector<int> > state;
    int h_score;

    Board(){
        board_size = 8;
        state.resize(board_size);
        for(int i = 0; i < state.size(); ++i){
            state[i].resize(board_size, 0);
        }
    }

    Board(const Board &b) : board_size(b.board_size), state(b.state), h_score(b.h_score){}

    Board & operator=(const Board &b){
        Board tmp(b);

        std::swap(state, tmp.state);
        std::swap(board_size, tmp.board_size);
        std::swap(h_score, tmp.h_score);

        return *this;
    }

};



void randomize(Board &board);
bool goalTest(Board *board);
int heuristic(Board *board);
vector<Board *> generateChildren(Board *board);
Board * generateRandomSuccessor(Board *board);



#endif