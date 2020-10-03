#use _author_ = 'Kuruvilla Jacob' 
import pickle
from _projectmodules import project 
ch=1
print('''If New member is being registered, its recommended to
to go through the facility file to see the available facilities ''')
print()
print('''New members are expected to pay the first year's fees in advance.
hence the date of enrollement to sports club is also taken as the date of
Payement of Fees''' )

while ch!=0:
    print("\n(1) Access Member File")
    print("(2) Access Fees File")
    print("(3) Access Facility File")
    print("(0) Exit Menu")
    ch=int(input("Enter Choice : "))
    if ch==1:
        while ch!=0:
            print("\n(1) Input New Member details")
            print("(2) Search for Member details")
            print("(3) Edit Member details")
            print("(4) Delete Member Records")
            print("(5) Display All Member Records")
            print("(0) Exit Menu")
            ch=int(input("Enter Choice : "))
            if ch==1:
                project.newmember()
            elif ch==2:
                project.searchmember()
            elif ch==3:
                project.editdetails()
            elif ch==4:
                project.deleterec()
            elif ch==5:
                project.display()
                
        ch=1
    elif ch==2:
        while ch!=0:
            print("\n(1) Display Fees File")
            print("(2) Members Fees due in a Month")
            print("(3) Update Fees File")
            print("(0) Exit Menu")
            ch=int(input("Enter Choice : "))
            if ch==1:
                project.dispfees()
            elif ch==2:
                project.duefees()
            elif ch==3:
                project.updatefees()
        ch=2
    elif ch==3:
        while ch!=0:
            print("\n(1) Add new facilites")
            print("(2) Display Facilites Available")
            print("(0) Exit Menu")
            ch=int(input("Enter Choice : "))
            if ch==1:
                project.addfac()
            elif ch==2:
                project.dispfac()
            
        ch=3
   

        



                
        

                    

