n = int(input())
x = 0
y = 0
for i in range(1, n+1):
    a, b, c = map(int, input().split())
    if a == 1:
        x += 1
    if b == 1:
        x += 1
    if c == 1:
        x += 1
    if x >= 2:
        y += 1
    x = 0
print(y)
