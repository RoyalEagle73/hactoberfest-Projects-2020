k, n, w = map(int, input().split())
a = 0
for i in range(1, w+1):
    a += i*k
z = a-n
if z < 0:
    print(0)
else:
    print(z)
