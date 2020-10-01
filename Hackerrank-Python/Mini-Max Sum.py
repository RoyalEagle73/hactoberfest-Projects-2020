#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the miniMaxSum function below.
def miniMaxSum(arr):
    arr.sort();
    max, min = 0, 0;
    for i in range(4):
        min += arr[i];
    for i in range(len(arr)-1,len(arr) -5 , -1):
        max += arr[i];
    print(min, max);
if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
