''' Problem Can Be found at : https://www.codechef.com/SSCC2020/problems/SSEC0006 '''
a = int(input())
b = int(input())
min = (a/2)*(b/2)
max = a*b
prime = []
for num in range(a, b + 1):
   if num > 1:
       for i in range(2, num):
           if (num % i) == 0:
               break
       else:
           prime.append(num)
y = []
for i in prime:
    for j in prime:
        if i*j <= max and i*j >= min and i!=j:
            h = [i,j]
            y.append(h)
res = list(set(map(lambda k: tuple(sorted(k)), y)))
y = []
for i  in res:
    y.append(list(i))
y.sort()
for i in y:
    m = ("{},{}").format(i[0],i[1])
    print(m)
