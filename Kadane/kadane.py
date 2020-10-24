import sys
def maxSubArraySum(a, size):
    max_so_far = -sys.maxsize - 1
    max_ending_here = 0

    for i in range(0, size):
        max_ending_here = max_ending_here + a[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here

        if max_ending_here < 0:
            max_ending_here = 0
    return max_so_far


# Driver function to check the above function
a = [-1, 0, 4, 2, -7, 1, 2, -3]
print("Maximum contiguous sum is", maxSubArraySum(a, len(a)))
