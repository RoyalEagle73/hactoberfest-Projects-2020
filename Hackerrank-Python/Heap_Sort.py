'''Heap Sort is a sorting technique in which is based on Heap data structure.
In this program we will first define Heapify Function. Heapify is a process to 
convert binary tree into heap data structure. After defining heapify, we will define our
heap sort function. We will apply this heap sort function on user input array.'''

'''Heapify function, our root node is at index i. We will first assume that 
the value atindex 'i' is the largest. Then we will find index of left and right child.
Then we will check if left and right child exist or not.Now, we will compare our value 
at index i with left and right child. If either of two children have greater value 
then "largest" will store the index of greater value and will swap
the values. if the largest is equal to index i then no swapping. This will be a recursive
funtion so that value gets to its correct position.'''

def HeapifyUp(items,length,index):
    largest=index
    leftchild=(index*2)+1 #finding index of leftchild
    rightchild=(index*2)+2 #finding index of right child
    
    if leftchild<length and items[index]<items[leftchild]: #checking left chid exist and comparing with parent node
        largest=leftchild
        
    if rightchild<length and items[largest]<items[rightchild]: #checking right chid exist and comparing with parent node
        largest=rightchild
        
    if largest!=index: #swaping
        items[index],items[largest] = items[largest],items[index] 
        
        HeapifyUp(items,length,largest) #recurssion
        
'''Now, we are creating our Max Heap function which will use heapify function to place
values at their correct position. MaxHeap will arrange the elements of the user input
array into max heap.'''
        
def MaxHeap(items):
    length=len(items)
    for i in range(length // 2 - 1, -1, -1): #last parent node
        HeapifyUp(items,length,i) 

'''Heap sort function will sort the array to increasing order'''    
def HeapSort(items):
    length=len(items)
    MaxHeap(items)
        
    for i in range(length-1, 0, -1): #extracting values one by one.
        items[i], items[0] = items[0], items[i]   # swaping 
        HeapifyUp(items, i, 0) 
 
'''User input array'''       

myarray=[]
n=int(input("Enter no. of elements you want in your array:"))

for j in range(0,n):
    element=int(input("Enter element:"))
    myarray.append(element)
    
print("Your Unsorted array is:",myarray)
   

    
'''Using HeapSort function to sort the array in increasing order'''

HeapSort(myarray)
k=len(myarray)
print ("Your Sorted array is:",myarray) 

    
        
        
    
    
