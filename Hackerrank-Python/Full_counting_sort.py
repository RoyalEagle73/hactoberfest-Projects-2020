#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countSort function below.
def countSort(arr):
    n=len(arr)
    l=[]
    for i in range(int(n/2)):
        arr[i][1]='-'
    for i in range(100):
        l.append("")
    for i in arr:
        l[int(i[0])]+=i[1]+" "
    for i in range(100):
        if l[i]!="":
            print(l[i],end='')

    

if __name__ == '__main__':
    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(input().rstrip().split())

    countSort(arr)
