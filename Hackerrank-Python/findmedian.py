def findMedian(arr):
    arr.sort()
    # check the length of the list odd or even
    if len(arr) % 2 == 0:
        # if the length of the list is even
        # the median is the average of the number of indexes n/2 + (n/2 - 1)
        a = int(len(arr)/2)
        b = a - 1
        c = (arr[a] + arr[b]) / 2
        return c
    else:
        # if the length of the list is odd
        # the median is the index n/2
        b = int(len(arr)/2)
        c = arr[b]
        return c

if __name__ == '__main__':
    # make a list of numbers from the input separated by ","
    arr = list(map(int, input("enter the list of numbers for which you want the median and separate them by ','\n").split(",")))
    result = findMedian(arr)
    print(result)
