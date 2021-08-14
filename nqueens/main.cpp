#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include "Problem.h"
#include "Agent.h"

using namespace std;

void saveResults(vector<Result> &results, string outFileName);
void showResults(string scriptFilename, string outFilename);

int main(int argc, char ** argv){

    // Run 10 tests of n-queens with simulated annealing, hill-climbing (steepest ascent and first-choice), hill climbing random restart,
    // and simulated annealing
    // Record search cost, percentage of solved problems, and graph against optimal
    string outFileName = "results.txt";
    string scriptFilename = "show_results.py";

    Result result;
    vector<Result> results;
    for(int i = 0; i < 10; ++i){
        // Create random initial state
        Board board;
        randomize(board);

        Agent agent(board);

        result = agent.hillclimb_sa();
        results.push_back(result);

        result = agent.hillclimb_fc();
        results.push_back(result);

        result = agent.hillclimb_rr();
        results.push_back(result);

        result = agent.simulated_annealing(10.0, 0.99, 0.001);
        results.push_back(result);

        // // Optimal
        // result = agent.astar();
        // results.push_back(result);
    }

    saveResults(results, outFileName);

    showResults(scriptFilename, outFileName);

    return 0;
}

void saveResults(vector<Result> &results, string outFileName){
    ofstream outFile;
    outFile.open(outFileName);

    // write labels
    outFile << "method\texec_time\tsolved\n";

    for(int i = 0; i < results.size(); ++i){
        outFile << results[i].method << "\t" << results[i].exec_time << "\t" << results[i].solved << "\n";
    }

    outFile.close();
}

void showResults(string scriptFilename, string outFilename){
    // char tmp[256];
    // getcwd(tmp, 256);
    // string cpath(tmp);
    //cpath += scriptFileName;

    string command = "python3 ";
    command += scriptFilename;
    command += " ";
    command += outFilename;

    system(command.c_str());
}
