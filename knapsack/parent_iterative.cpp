#include<bits/stdc++.h>
using namespace std;

int T[102][102];

int knapsack(int wt[], int val[], int W, int n){
  //Base changes to initialization of Table
  for(int i=0; i<n+1; i++){
    for(int j=0; j<W+1; j++)
      T[i][j] = 0;
  }

  //Implementing choice diagram - 
  for(int i=1; i<n+1; i++){
    for(int j=1; j<W+1; j++){
      if(wt[i-1] <= j){
        T[i][j] = max(val[i-1]+T[i-1][j-wt[i-1]], T[i-1][j]);
      } else {
        T[i][j] = T[i-1][j];
      }
    }
  }

  return T[n][W];
}

int main()
{
  int val[] = {60, 100, 120, 130};
  int wt[] = {10, 20, 30, 30};
  int W = 50;
  int n = 4;
  cout << knapsack(wt, val, W, n);
}