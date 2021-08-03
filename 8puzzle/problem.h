#ifndef PROBLEM_H_
#define PROBLEM_H_

#include "puzzle.h"
#include <vector>

int goalTest(Puzzle *);
int heuristic(Puzzle *);
Puzzle * transition(Puzzle *curr_node, int action);
vector<Puzzle *> generateChildren(Puzzle *curr_node);


#endif