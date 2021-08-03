#include "puzzle.h"
#include "problem.h"
#include <cstddef>

Puzzle::Puzzle()
{
    //Initialize State
    state.resize(9, -1);
    // Intiialize path cost
    path_cost = 0;
    f_score = 0;

    // Initialize Parent
    parent = nullptr;
}