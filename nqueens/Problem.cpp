#include "Problem.h"
#include <stdlib.h>

void randomize(Board &board){
    // Choose a random position in each column
    for(int i = 0; i < board.board_size; ++i){
        int random = rand() % board.board_size;
        for(int j = 0; j < board.board_size; ++j){
            if(j == random)
                board.state[j][i] = 1;
        } // Iterate through rows
    }// Iterate through columns

    board.h_score = heuristic(&board);
}

int heuristic(Board *board){
    int attacking = 0;

    // Search through each column for its queen
    for(int i = 0; i < board->board_size; ++i){
        for(int j = 0; j < board->board_size; ++j){
            if(board->state[j][i]){ // queen found in column

                int Arow = j;
                int Acol = i;

                //Check entire row
                for(int k = 0; k < board->board_size; ++k){
                    if(k != Acol && board->state[j][k])
                        attacking++;
                }

                // Check up left diag
                int row = Arow - 1;
                int col = Acol - 1;
                while(row >= 0 && col >= 0){
                    if(board->state[row][col])
                        attacking++;
                    col--;
                    row--;
                }

                // check up right diag
                row = Arow - 1;
                col = Acol + 1;
                while(row >= 0 && col <= board->board_size - 1){
                    if(board->state[row][col])
                        attacking++;
                    col++;
                    row--;
                }

                // Bottom right diag
                row = Arow + 1;
                col = Acol + 1;
                while(row <= board->board_size - 1 && col <= board->board_size - 1){
                    if(board->state[row][col])
                        attacking++;
                    row++;
                    col++;
                }

                // Bottom left diag
                row = Arow + 1;
                col = Acol - 1;
                while(col >= 0 && row <= board->board_size - 1){
                    if(board->state[row][col])
                        attacking++;
                    col--;
                    row++;
                }
            }
        }
    }

    return (int)attacking / 2;
}

bool goalTest(Board *board){
    if(heuristic(board) == 0){
        return true;
    }

    return false;
}

vector<Board *> generateChildren(Board *board){
    // Create new board for each position queen in column can go to
    vector<Board *> children;

    for(int i = 0; i < board->board_size; ++i){
        // find queen row
        int qRow;
        for(int j = 0; j < board->board_size; ++j){
            if(board->state[j][i]){
                qRow = j;
                break;
            }
        }// Itr through rows

        // Create new states for each non queen space in column by swapping
        for(int j = 0; j < board->board_size; ++j){
            if(j != qRow){
                Board *newBoard = new Board;
                newBoard->state = board->state;
                newBoard->board_size = board->board_size;
                newBoard->state[j][i] = 1;
                newBoard->state[qRow][i] = 0;
                newBoard->h_score = heuristic(newBoard);

                children.push_back(newBoard);
            }
        }
    } // Itr through columns

    return children;
}

Board * generateRandomSuccessor(Board *board){
    int randomColumn = rand() % 8;
    int randomRow = rand() % 8;

    // find queen in randomColumn
    int qRow;
    for(int i = 0; i < board->board_size; ++i){
        if(board->state[i][randomColumn])
            qRow = i;
    }

    // Create state
    Board *newBoard = new Board;
    newBoard->state = board->state;
    newBoard->board_size = board->board_size;
    
    // Make the swap
    if(randomRow == qRow){
        if(qRow == 7){
            randomRow = 6;
        }
        else {
            randomRow = randomRow + 1;
        }
    }
    newBoard->state[qRow][randomColumn] = 0;
    newBoard->state[randomRow][randomColumn] = 1;
    newBoard->h_score = heuristic(newBoard);

    return newBoard;
}