from itertools import product
a=[eval(x) for x in input().split()]
b=[eval(x) for x in input().split()]
print (tuple((product(a,b))))
