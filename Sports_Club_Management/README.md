# Sports Club Management
A school project where I've been asked to create a Pyhton Program for managing a Sports Club.
So basically it includes functions such as registering a new member, auto assigning them codes, calculating their yearly fees etc.
Bear with me I'm just student and my code might not be the best or efficent but its all coded by me and its my ideas.

# Certain requirments before running the program
Install the the Python Library "Tabulate" in the Python Scripts directory using the command ```pip install tabulate```

Copy the folder **_projectmodules** to the Python Lib directory

I have provided a Member, Facility and a Fees file , make sure to keep it in the same folder as **Sports Club Management.py**

# Functions of the Program
The Program contains the follwing menus:
## 1) Access Member file
Which contains further Submenus:
##### a)Input New member:
Allows you to chose the number of members to be added and then proceeds to take information such as **Name, Phone Number, Address,
the date of enrollement and the specific facilities they would like to Join**. A unique 8 character alhpanumeric code will be generated for each member
and the dates entered will be validated
##### b)Search for member details:
Upon entering the unique Alphanumeric code provided to each member, they will be able to view the member details
##### c)Edit member details:
The user will be able to edit detials of the members such as Phone number ,Address and the Facilities they wish to join
##### d)Delete member records:
Upon entering the unique Alphanumeric code provided to each member, user can delete a member from the system

**Note: If the member's fees is overdue, the deletion proccess will not take place**
##### e)Display all Member records:
Self Explainatory
## 2) Access Fees file:
##### a)Display Fees File:
Displays the Member code, date of payement and the next due date, which is Automatically calculated
##### b)Members Fees due in a Month
Displays all Member details along with their due date
##### b)Update fees file:
Upon entering the member code, the user us able to update the member's fees pay date
**Note: The payment date is taken as todays date**
## 3) Access Facility file
##### a)Members Fees due in a Month
Allows user to add new Facilities, the Fcaility code will be automatically generated.
Validation is done to check if the new facility being added already exists.
##### b)Display Facilities Available
Displays the Fcaility code and Facility Name






