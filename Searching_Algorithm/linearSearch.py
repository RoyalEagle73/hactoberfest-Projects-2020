#Program For Searching An element through Linear Approach

def linearSearch(n_list,search_key):
    for index,val in enumerate(n_list):
        if val == search_key:
            return index
    return -1


list1 = [1,2,3,4,5,6,7,8,9,10]
key = 1

print(linearSearch(list1,key))
