# Banking application
import time
class banking:
    bank_name="sbi"
    def __init__(self,name,acc_no,ava_bal=0):
        self.name=name
        self.acc_no=acc_no
        self.ava_bal=ava_bal
    def deposit(self,amt):
        self.ava_bal+=amt
        print"available balance is:",self.ava_bal
        time.sleep(5)
    def withdraw(self,amt):
        if amt>self.ava_bal:
            print"insufficient account balance"
            time.sleep(5)
        else:
            self.ava_bal-=amt
            print "available balance is:",self.ava_bal
            time.sleep(5)
    def mini_statement(self):
        print "available balance is:",self.ava_bal
        time.sleep(5)
print"welcome to the {}".format(banking.bank_name)
name=input("enter customer name")
acc_no=input("enter the customer account no")
obj=banking(name,acc_no)
a=True
while a:
    inp=input("d=deposit\nw=withdraw\nm=mini-statement\ne=exit\nenetr a option")
    if inp=="d" or inp=="D":
             amt=input("enter the amount you want to deposit")
             obj.deposit(amt)
    elif inp=="w" or inp=="W":
             amt=input("enter the amount you want to withdraw")
             obj.withdraw(amt)
    elif inp=="m"or inp=="M":
             obj.mini_statement()
    elif inp=="e" or inp=="E":
             a=False
    else:
             print"enter a valid option"
             time.sleep(5)
