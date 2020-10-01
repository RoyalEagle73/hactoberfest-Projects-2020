import math

def div(n):
    l_div= int(math.sqrt(n) + 1)
    lrg_div = []
    for i in range(1, l_div):  # As the divsior of any natural number 'n' have range from 1 to (square root of n)+1
        if n % i == 0:
            yield i
            if i*i != n:
                lrg_div.append(n / i)
    for divisor in reversed(lrg_div):
        yield divisor
n = int(input("Enter a number between 1 to 1000000"))
print(len(list(div(n))))
