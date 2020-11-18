#Given the participants' score sheet for your University Sports Day, you are required to find the runner-up score. You are given  scores. Store them in a list and find the score of the runner-up.

#Input Format

#CODE 
if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    # Find the Runner-Up Score! in Python - Hacker Rank Solution START
    print(sorted(list(set(arr)))[-2])
