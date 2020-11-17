#!/bin/python3

import os
import sys

#
# Complete the equalStacks function below.
#
def equalStacks(h1, h2, h3):
    #
    # Write your code here.
  
    
    ####

    s1=sum(h1)
    s2=sum(h2)
    s3=sum(h3)
    while h1 and h2 and h3:
        m=min(s1,s2,s3)
        while s1>m:
            s1=s1-h1.pop(0)
        while s2>m:
            s2=s2-h2.pop(0)
        while s3>m:
            s3=s3-h3.pop(0)
        if s1==s2==s3:
            return s1
    return 0
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n1N2N3 = input().split()

    n1 = int(n1N2N3[0])

    n2 = int(n1N2N3[1])

    n3 = int(n1N2N3[2])

    h1 = list(map(int, input().rstrip().split()))

    h2 = list(map(int, input().rstrip().split()))

    h3 = list(map(int, input().rstrip().split()))

    result = equalStacks(h1, h2, h3)

    fptr.write(str(result) + '\n')

    fptr.close()
