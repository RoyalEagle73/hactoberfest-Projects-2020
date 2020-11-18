#Made by Rohan Sharma
#Arithmetic Calculator
class calci():
    def __init__(self,a,b):
        self.a = a
        self.b = b
    def add(self):
        return self.a + self.b
    def mul(self):
        return self.a * self.b
    def div(self):
        return self.a / self.b
    def sub(self):
        return self.a - self.b
    def mod(self):
        # Modulo operator works like a % b returns remainder when a is divided by b
        # example 10 % 3 == 1
        return self.a % self.b


a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
obj=calci(a, b)
choice=1

while choice != 0:
    print("0. Exit")
    print("1. Add")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Modulo")
    choice=int(input("Enter choice: "))
    if choice == 1:
        print("Result: ", obj.add())
    elif choice == 2:
        print("Result: ", obj.sub())
    elif choice == 3:
        print("Result: ", obj.mul())
    elif choice == 4:
        print("Result: ", round(obj.div(), 2))
    elif choice == 5:
        print("Result: ", obj.mod())
    elif choice == 0:
        print("Exiting the calculator")
    else:
        print("Invalid choice!!")
print()
