import math

def min_coin_td(n, coinArr, t, dp):
    if n == 0:
        return 0
    if dp[n] != 0:
        return dp[n]
    ans = math.inf
    for i in range(t):
        if n - coinArr[i] >= 0:
            subprob = min_coin(n - coinArr[i], coinArr, t, dp)
            ans = min(subprob, ans)
    dp[n] = ans + 1
    return dp[n]

def min_coin_bu(n, coinArr, t):
    dp = [0  for i in range(n + 1)]
    for i in range(1, n + 1):
        dp[i] = math.inf
        for j in range(0,t):
            if (i - coinArr[j]) >= 0:
                dp[i] = min(dp[i], dp[i - coinArr[j]] + 1)
    return dp[n]

if __name__ == "__main__":
    total_amt = int(input("Enter the total amount :- "))
    #type_c = int(input("Enter the available types of coin :- "))
    print("Enter all types coins :-", end = " ")
    typeArr = list(map(int, input().split(" ")))
    typeC = len(typeArr)
    dp = [0 for i in range(total_amt + 1)]
    #x = min_coin_td(total_amt,typeArr,typeC, dp)
    x = min_coin_bu(total_amt, typeArr, typeC)
    print(x)
