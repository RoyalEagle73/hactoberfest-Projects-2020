#include <bits/stdc++.h>
using namespace std;

static int T[102][1002];

int knapsack(int wt[], int val[], int W, int n)
{
  // Base case - Think of smallest valid input
  if (n == 0 || W == 0)
    return 0;

  // Implementing choice diamgram
  // /DP/KNAPSACK/parent_kanpsack_choice.png

  if (T[n][W] != -1)
    return T[n][W];

  if (wt[n - 1] <= W)
    return T[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),
                         knapsack(wt, val, W, n - 1));

  else
    return T[n][W] = knapsack(wt, val, W, n - 1);
}

int main()
{
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int W = 50;
  int n = 3;
  memset(T, -1, sizeof(T));
  cout << knapsack(wt, val, W, n);
}