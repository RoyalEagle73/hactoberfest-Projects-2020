lst=[]
def addnum(lst):
    return sum(lst)
total_num_in_list=input("total_num_in_list")
for i in range(0,total_num_in_list):
    a=input("enter value")
    lst.append(a)
print addnum(lst)    
