s = set(input().split())
ans = True
for i in range(int(input())):
    t = set(input().split())
    if (s > t) == False:
        ans = False
        break
print(ans)     