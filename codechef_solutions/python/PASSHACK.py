''' Problem : https://www.codechef.com/problems/PASSHACK'''
a = int(input())

for i in range(a):
    g = list(map(int,input()))
    strr = ""
    if len(g)<10 and len(g)>3:
        for i in g:
            if i>1:
                t = i-2
                strr += str(t)
            else:
                strr += str(i)
        print(strr)
    else:
        for i in g:
            strr += str(i)
        print(strr)
