#use _author_ = 'Kuruvilla Jacob'
import uuid
import pickle
from tabulate import tabulate
from datetime import date,timedelta
def codegen(codelist):
    valid=0
    while valid==0:
        id = uuid.uuid1()
        code=''
        for k in range(8):
            code+=id.hex[k]
        valid=1
        return code
                
def namevalid():
    valid=0
    while valid==0:
        name=input("Enter Name")
        if len(name)>2 and name.isalnum()==False:
            valid=1
        else:
            print("Invalid Name, enter again")
    return name
def datevalidation():
    valid=0
    today=date.today()
    while valid==0:
        doj=input("Ente date in DD/MM/YYYY : ")
        d,m,y=[int(x) for x in doj.split('/')]
        try:
            doj=date(y,m,d)
            if doj>today:
                print("Invalid Date, Enter again")
            else:
                valid=1
                return doj
        except:
            print('Inavlid date, Enter again')
    return date
def facilityvalid():
    valid=0
    print("\nMinimum 1 Facility must be entered, click enter to leave a facility blank")
    while valid==0:
        fc1=input("First Facility Code")
        fc2=input("Second Facility Code")
        fc3=input("Third Facility Code")
        if fc1==fc2 and fc1!='' or fc2==fc3 and fc2!='' or fc3==fc1 and fc3!='': 
            valid==0
            print("Duplicate Facility Code entered, please enter the code again\n")
        elif fc1=='' and fc2=='' and fc3=='':
            print("All fields are empty, please enter the code again\n")
            valid==0
        else:
            with open("Facility File.dat",'rb')as fac:
                list1=[]
                list1.append('')
                while True:
                    try:
                        rec=pickle.load(fac)
                        list1.append(rec[0])
                    except:
                        if (fc1 not in list1) or (fc2 not in list1) or (fc3 not in list1):
                            print("Invalid Code Entered")
                            break
                        else:
                            valid=1
                            return fc1,fc2,fc3
def editdetails():
    with open('Member File.dat','rb')as files:
        code=input("Enter code of Member or to cancel enter 0")
        found=0 
        if code=='0':
            return None
        recnew=[]
        try:
            while True:
                rec=pickle.load(files)
                recnew.append(rec)
        except:
            for k in recnew:
                if k[0]==code:
                    found=1
                    choice=1
                    while choice!=0:
                        print("\nEnter 1 to edit Address")
                        print("Enter 2 to edit Phone Number")
                        print("Enter 3 to edit Facility")
                        print("Enter 0 to exit")
                        choice=int(input("Enter your Choice : "))
                        if choice==1:
                            rec[3]=input("Enter New Adress : ")
                        elif choice==2:
                            rec[4]=int(input("Enter New Phone Number : "))
                        elif choice==3:
                            rec[5],rec[6],rec[7]=facilityvalid()
            with open('Member File.dat','wb')as files:
                pickle.dump(k,files)
            if found==0:
                print("Code entered does not exist, exiting function\n")
def display():
    with open("Member File.dat",'rb') as f:
        try:
            list1=[]
            while True:
                rec=pickle.load(f)
                list1.append(rec)
        except:
            print(tabulate(list1,headers=['Code','Name','Date','Address','Phone Number','Fc1','Fc2','Fc3'], tablefmt='github'))
def deleterec():
    with open("Member File.dat","rb") as recdel:
        today=date.today()
        feesdel=open("Fees file.dat","rb")
        found,overdue=0,0
        feesnew=[]
        recnew=[]
        code=input("\nEnter code of Member to be deleted or to cancel Enter 0 ")
        if code=='0':
            return None
        try:
            while True:
                fees=pickle.load(feesdel)
                rec=pickle.load(recdel)
                if code!=fees[0]:
                    feesnew.append(fees)
                else:
                    diff=(fees[2]-today).days
                    if diff<=0:
                        overdue=1
                        feesnew.append(fees)

                if code!=rec[0]:
                    recnew.append(rec)
                elif code==rec[0] and overdue==1:
                    recnew.append(rec)
                else:
                    found=1    
        except:
            feesdel.close()
            with open("Member File.dat","wb") as recdel:
                feesdel=open("Fees file.dat","wb")
                for k in recnew:
                    pickle.dump(k,recdel)
                for j in feesnew:
                    pickle.dump(j,feesdel)
        if found==0:
            print("Member code not found, exiting function\n")
        elif overdue==1:
            print("Member fees is Overdue, record can only be deleted after payment of fees\n")
        else:
            print("Member record successfuly deleted\n")
def newmember():
    with open('Member File.dat','rb')as member:
        recnew=[]
        try:
            while True:
                rec=pickle.load(member)
                recnew.append(rec)
        except:
            with open('Member File.dat','wb')as member:
                n=int(input("Enter Number of New Members"))
                for loop in range(n):
                    code=codegen(recnew)
                    print("Your Unique Member code=",code)
                    name=namevalid()
                    doj=datevalidation()
                    address=input("Enter Adress : ")
                    phone=int(input("Enter Phone Number : "))
                    print('''The annual membership fee is Rs. 10,000 and for every 
facility (sports) selected a member has to pay Rs. 2,000 annually''')
                    fc1,fc2,fc3=facilityvalid()
                    newrec=[code,name,doj,address,phone,fc1,fc2,fc3]
                    pickle.dump(newrec,member)
                    feesnew(doj,fc1,fc2,fc3,code)
                for k in recnew:
                    pickle.dump(k,member)

def caldue(daypaid):
    diff=timedelta(days=365)
    duedate=daypaid+diff
    return duedate              
def feesnew(doj,fc1,fc2,fc3,code):
    with open('Fees File.dat','rb')as fees:
        feeslist=[]
        try:
            while True:
                feesrec=pickle.load(fees)
                feeslist.append(feesrec)
        except:
            with open('Fees File.dat','wb')as fees:
                duedate=caldue(doj)
                c=len(fc1+fc2+fc3)
                feeslist.append([code,doj,duedate,10000+(2000*c)])
                for k in feeslist:
                    pickle.dump(k,fees)
                    
def dispfees():
    with open('Fees File.dat','rb')as fees:
        recnew=[]
        try:
            while True:
                rec=pickle.load(fees)
                recnew.append(rec)
        except:
            print(tabulate(recnew,headers=['Code','Paid Date','Next Due Date','Amount Paid'], tablefmt='github'))
def dispfac():
    with open("Facility File.dat","rb")as fac:
        recnew=[]
        try:
            while True:
                rec=pickle.load(fac)
                recnew.append(rec)
        except:
            title=['Code','Facility']
            print('{:<3} {:<10}'.format(title[0],title[1]))
            print('='*13)
            for k in recnew:
                print('{:<3} {:<10}'.format(k[0],k[1]))
                print('-'*13)
def duefees():
    with open("Fees File.dat","rb")as fees:
        diff=timedelta(days=30)
        try:
            today=date.today()
            recnew=[]
            while True:
                rec=pickle.load(fees)
                diff=(rec[2]-today).days
                if diff<=30:
                    recnew.append([rec[0],rec[2]])
        except:
            print(tabulate(recnew,headers=['Code','Due Date'], tablefmt='github'))
            
def updatefees():
    with open("Member file.dat","rb")as member:
        today=date.today()
        valid=0
        code=input("Enter Code of Member : ")
        try:
            while True:
                rec=pickle.load(member)
                if code==rec[0]:
                    print("Fees Paid Succesfully")
                    valid=1
                    f1,f2,f3=rec[5],rec[6],rec[7]
        except:
            if valid==0:
                print("Invalid Code, Terminating Function\n")
                return()
            print('3')
            with open ("Fees file.dat",'rb')as fees:
                print('4')
                try:
                    recnew=[]
                    while True:
                        print('5')
                        rec=pickle.load(fees)
                        print(rec)
                        if rec[0]==code:
                            rec[1]=today
                            duedate=caldue(today)
                            rec[2]=duedate
                            rec[3]=10000+(2000*len(f1+f2+f3))
                        recnew.append(rec)
                except:
                    print(recnew)
                    with open("Fees file.dat","wb")as fees:
                        for k in recnew:
                            print(k)
                            pickle.dump(k,fees)
def addfac():
    with open("Facility file.dat","rb")as fac:
        try:
            newfac=input("\nEnter name of new Facility to be added : ")
            c=1
            recnew=[]
            valid=1
            while True:
                c+=1
                rec=pickle.load(fac)
                if rec[1].lower()==newfac.lower():
                    valid=0
                recnew.append(rec)
        except:
            if valid==0:
                print("Facility Already exists\n")
                return()
            with open("Facility file.dat","wb")as fac:
                recnew.append([c,newfac])
                for k in recnew:
                    pickle.dump(k,fac)
def searchmember():
    with open("Member file.dat","rb")as member:
        code=input("Enter Member code")
        title=['Code','Name','Date','Address','Phone','F1','F2','F3']
        valid=0
        try:
            while True:
                rec=pickle.load(member)
                if rec[0]==code:
                    valid=1
                    print('='*88)
                    print('{:<10} {:<16} {:<12} {:<22} {:<10} {:<3} {:<3} {:<3}'.format(title[0],title[1],title[2],title[3],title[4],title[5],title[6],title[7]))
                    print('-'*88)
                    print('{:<10} {:<16} {:<12} {:<22} {:<10} {:<3} {:<3} {:<3}'.format(rec[0],rec[1],str(rec[2]),rec[3],rec[4],rec[5],rec[6],rec[7]))
                    print('='*88)
        except:
            if valid==0:
                print("Invalid Code Entered\n")
    
