#!/usr/bin/python3

import sys
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def readLabels(file):
    labels = (file.readline()).split()
    return labels


def main():
    filename = sys.argv[len(sys.argv) - 1]
    file = open(filename, 'r')
    # read labels
    labels = readLabels(file)

    exec_times = []
    has_solved = []
    methods = []
    methodIndices = {}
    # read in data line by line
    while True:
        data = file.readline().split()

        # check for end of file
        if not data:
            break

        # check whether method has already been seen
        if data[0] not in methodIndices.keys():
            # Add method to known methods and index to find the specific data
            methods.append(data[0])
            methodIndices[data[0]] = len(methods) - 1
            exec_times.append([])
            has_solved.append([])

        exec_times[methodIndices[data[0]]].append(float(data[1]))

        if int(data[2]) == 1:
            has_solved[methodIndices[data[0]]].append(1)
        else:
            has_solved[methodIndices[data[0]]].append(0)

    # end of file reading
    file.close()


    #Plot #1 - Average execution time and solves for each method
    # Find average execution time of each method
    avg_execs = []
    for li in exec_times:
        avg_execs.append(sum(li)/len(li))

    percent_solves = []
    for item in has_solved:
        percent_solves.append(sum(item)/len(item))

    x = np.arange(len(methods))
    width = 0.35

    fig, ax = plt.subplots()
    rects1 = ax.bar(x - width/2, avg_execs, width, label='Average Execution Time(ms)')
    rects2 = ax.bar(x + width/2, percent_solves, width, label='Total Solves(%)')

    ax.set_xticks(x)
    ax.set_xticklabels(methods)
    ax.set_title('Performance of searching methods on Nqueens problem')
    ax.legend()

    ax.bar_label(rects1, padding=3)
    ax.bar_label(rects2, padding=3)

    fig.tight_layout()

    plt.show()




if __name__ == "__main__":
    main()