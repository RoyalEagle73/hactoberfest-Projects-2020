def findMedian(s, arr):
    arr.sort()
    b = int(s/2)
    c = arr[b]
    return c


if __name__ == '__main__':

    n = int(input())
    arr = list(map(int, input().split()))
    result = findMedian(n, arr)
    print(result)
