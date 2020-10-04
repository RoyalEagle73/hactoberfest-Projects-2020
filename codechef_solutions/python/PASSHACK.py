''' Problem : https://www.codechef.com/problems/PASSHACK'''
a = int(input())

for i in range(a):
    g = input()
    strr = ""
    for j in g:
        strr += str(int(j)-2)
    print(strr)
