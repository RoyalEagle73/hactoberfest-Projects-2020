#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    a = list(map(int, input().rstrip().split()))
    x=list(a)
    for i in range(d):
        y=x.pop(0)
        x.append(y)
    for i in x:
        print(i,end=" ")
    
