#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxSubarray function below.
def maxSubarray(arr):
    resC=resNc=arr[0]
    max_so_far =arr[0] 
    curr_max = arr[0]
    if(arr[0]>0):
        resNc=0 
        curr_max=0
    res=[0,0]
    for i in arr:
        resNc=max(resNc,i,resNc+i) 
        curr_max = max(i, curr_max + i)     #Modified Kadane's Algorithm. O(n)
        max_so_far = max(max_so_far,curr_max)
    res[0]=resC=max_so_far
    res[1]=resNc
    return res
        



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        result = maxSubarray(arr)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
