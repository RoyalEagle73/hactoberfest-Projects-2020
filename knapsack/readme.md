First thing how do we verify it's a DP quetion
1. Check if you've choice given
2. Check if we've to optimize our value

<!-- Good coders never start with top down approach. -->
To get started for DP we have two ways:-
1. Top Down approach
2. Recursive + Memoization

I suggest you to never start with top down approach.
Best approach to start is Recursive + Memoization
It's easy to thing and is powerful as top down approach

So, 1st step make a choice diamgram - which will become easiest part to implement
and then think of base case

Base Case - Think of smallest valid input, is a great way to think.
Now implement choice diagram

2nd Step is memoization
To memoize and program we've to make a table 'T' of dimension m*n.
Now, On which size of matrix depends upon?

Check in every fn call which variables are changing.
Now initialize complete matrix with -1
Now before calling any function first check whether at T[m][n] is there value present present but not -1. Then simply return that value or else call the funtion and save that returned value to 
T[m][n]. 


Variants of Knapsack problem
1. Subset sum problem
2. Equal sum problem
3. Count of subset sum
4. Minimum subset sum off
5. Target sum
6. Number of subset <= given difference