n = int(input("Enter a number: "))
sum = 0
temp = n
while temp > 0:
   digit = temp % 10
   sum += digit ** 3
   temp //= 10

# display the result
if n == sum:
   print(n,"is an Armstrong number")
else:
   print(n,"is not an Armstrong number")
