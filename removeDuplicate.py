# This program is used to remove duplicated values from a list passed by parameter

def compare(list):
    newList = []
    for x in list:
        if x not in newList:
            newList.append(x)    
    return newList
