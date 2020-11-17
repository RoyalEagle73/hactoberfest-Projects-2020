from math import factorial
x=[int(i) for i in input().split()]
N=x[0]
k=x[1]
count=0
for n in range(1,N+1):
    for r in range(1,n):
        if (factorial(n))/(factorial(r)*factorial(n-r))>k:
            count+=(n-2*r+1)
            break
print(count)
