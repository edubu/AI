#!/usr/bin/python3

import sys;
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def readLabels(filename):
    f = open(filename, 'r')
    labels = (f.readline()).split()
    return labels



def main():
    filename = sys.argv[len(sys.argv) - 1]
    # read labels
    labels = readLabels(filename)

    # gather all data
    exec_times

    



if __name__ == "__main__":
    main()