# Enter your code here. Read input from STDIN. Print output to STDOUT


num=int(input())
new=list()
for i in range(num):
    q=list(map(int,input().split()))
    if q[0]==1:
        new.append(q[1])
    elif q[0]==2:
        new.pop(0)
    elif q[0]==3:
        print(new[0])
