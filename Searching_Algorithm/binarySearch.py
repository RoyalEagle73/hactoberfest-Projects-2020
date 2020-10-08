# This type of Searching follows Divide and Conquer Approach Which takes lesser time than linearSearch

def binarySearch(n_list,s,l,search_key):
    """Return the index of the key if present, -1 otherwise"""

    mid = s + (l-s) // 2
    if s <= l:
        if search_key == n_list[mid]:
            return mid
        elif search_key < n_list[mid]:
            return binarySearch(n_list,s,mid-1,search_key)
        else:
            return binarySearch(n_list,mid+1,l,search_key)
    else:
        return -1


n_list = [1,2,3,4,5,6,7,8,9,10]
key = 11

print(binarySearch(n_list,0,len(n_list)-1,key))

