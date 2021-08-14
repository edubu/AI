#include "Agent.h"
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

Agent::Agent(Board board){
    initialState = board;
}

Result Agent::hillclimb_sa(){
    // Start timer
    auto start = high_resolution_clock::now();

    Result result;
    result.method = "HC_SA";
    Board *currNode = &initialState;
    CompareBoardH compb;
    while(true){
        // Obtain children
        vector<Board *> children = generateChildren(currNode);

        // Sort children
        sort(children.begin(), children.end(), compb);

        Board *bestNode = children.back();
        if(bestNode->h_score <= currNode->h_score)
            break;
        else {
            currNode = bestNode;
            if(goalTest(currNode))
                break;
        }
    }

    if(goalTest(currNode))
        result.solved = 1;
    else 
        result.solved = 0;


    //End timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    result.exec_time = (double)duration.count() / 1000.0;

    // Return
    return result;
}

Result Agent::hillclimb_sa(Board *startingState){
    // Start timer
    auto start = high_resolution_clock::now();

    Result result;
    result.method = "HC_SA";
    Board *currNode = startingState;
    CompareBoardH compb;
    while(true){
        // Obtain children
        vector<Board *> children = generateChildren(currNode);

        // Sort children
        sort(children.begin(), children.end(), compb);

        Board *bestNode = children.back();
        if(bestNode->h_score <= currNode->h_score)
            break;
        else {
            currNode = bestNode;
            if(goalTest(currNode))
                break;
        }
    }

    if(goalTest(currNode))
        result.solved = 1;
    else 
        result.solved = 0;


    //End timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    result.exec_time = (double)duration.count() / 1000.0;

    // Return
    return result;
}

Result Agent::hillclimb_fc(){
    // Start timer
    auto start = high_resolution_clock::now();

    Result result;
    result.method = "HC_FC";
    Board *currNode = &initialState;

    int try_limit = 56;
    int tries = 0;
    while(tries < 56){
        Board *randomSuccessor = generateRandomSuccessor(currNode);
        if(randomSuccessor->h_score < currNode->h_score){
            currNode = randomSuccessor;
            if(goalTest(currNode))
                break;
            tries = 0;
        }
        else {
            tries++;
        }
    }

    if(goalTest(currNode))
        result.solved = 1;
    else
        result.solved = 0;


    // End timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    result.exec_time = (double)duration.count() / 1000.0;

    return result;
}

Result Agent::hillclimb_rr(){
    // Start timer
    auto start = high_resolution_clock::now();

    Result result;
    result.method = "HC_RR";

    int try_limit = 100;
    int tries = 0;

    while(tries < try_limit){
        Board board;
        randomize(board);
        Board *currBoard = &board;
        Result interResult = hillclimb_sa(currBoard);
        if(interResult.solved)
            break;
        else
            tries++;
    }
    result.solved = 1;

    // End timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    result.exec_time = (double)duration.count() / 1000.0;

    return result;
}

Result Agent::simulated_annealing(double initialTemp, double decay, double threshold){
    //Start timer
    auto start = high_resolution_clock::now();
    Result result;
    result.method = "SA";

    Board *currNode = &initialState;

    double temp = initialTemp;
    double temp_min = threshold;
    double alpha = decay;
    bool foundSolution = false;
    result.solved = 0;

    while(temp > temp_min && !foundSolution){

        //Choose random successor
        Board *randomSuccessor = generateRandomSuccessor(currNode);
        if(randomSuccessor->h_score == 0){
            foundSolution = true;
            currNode = randomSuccessor;
            result.solved = 1;
            break;
        }

        int change = currNode->h_score - randomSuccessor->h_score;

        if(change > 0)
            currNode = randomSuccessor;
        else{
            double prob = exp((double)change/temp);
            if(prob > rand())
                currNode = randomSuccessor;
        }

        temp *= alpha;
    }

    // if(goalTest(currNode))
    //     result.solved = 1;
    // else
    //     result.solved = 0;

    // End timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    result.exec_time = (double)duration.count() / 1000.0;

    return result;
}
