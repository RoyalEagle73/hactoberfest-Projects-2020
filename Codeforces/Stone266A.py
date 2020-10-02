n = int(input())
a = list(input())
count = 0
z = ''
for i in a:
    if z == i:
        count = count+1
    else:
        z = i
print(count)
