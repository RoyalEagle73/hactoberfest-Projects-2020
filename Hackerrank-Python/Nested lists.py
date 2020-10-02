if __name__ == '__main__':
    nums=[]
    lst=[]
    for _ in range(int(input())):
        name = input()
        score = float(input())
        nums+=[[name,score]]
        lst.append(score)
    x=sorted(set(lst))[1]

    for i,j in (sorted(nums)):
        if j==x:
            print(i)