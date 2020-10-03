from itertools import product
A,B = (map(int,input().split()) for _ in range(2))
print (' '.join(map(str,list(product(A,B)))))