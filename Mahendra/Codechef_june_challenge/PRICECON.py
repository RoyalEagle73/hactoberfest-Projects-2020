# cook your dish here
for i in range(int(input())):
    t,k = map(int,input().split())
    li=list(map(int, input().split()))
    a=sum(li)
    
    li1=[]
    for i in range(len(li)):
        if(li[i]>k):
            li[i]=k
            li1.append(li[i])
        else:
            li1.append(li[i])
    print(abs(a-sum(li1)))
