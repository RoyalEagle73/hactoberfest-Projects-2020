import calendar,time

yy = int(input("Enter the year : "))
mm = int(input("Enter the month : "))

print("Displaying calendar : ")
time.sleep(2)
print(calendar.month(yy,mm))

'''
OUTPUT

Enter the year : 2020
Enter the month : 10
Displaying calendar : 
    October 2020
Mo Tu We Th Fr Sa Su
          1  2  3  4
 5  6  7  8  9 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30 31
'''