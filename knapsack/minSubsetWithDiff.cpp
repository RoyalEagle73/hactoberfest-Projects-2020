#include <iostream>
#include <vector>
using namespace std;

int subsetSum(vector<int> &arr, int sum, int n)
{
  bool T[n+1][sum+1];
  for(int i=0; i<n+1; i++){
    for(int j=0; j<sum+1; j++){
      if(i==0) T[i][j] = false;
      if(j==0) T[i][j] = true;
    }
  }

  for(int i=1; i<n+1; i++){
    for(int j=1; j<sum+1; j++){
      if(arr[i-1] <= j)
        T[i][j] = T[i-1][j-arr[i-1]] || T[i-1][j];
      else
        T[i][j] = T[i-1][j];
    }
  }
  
  vector<int> V;
  for(int i=0; i<=sum/2; i++){
    if(T[n][i] == true)
      V.push_back(i);
  }

  return sum - 2*V[V.size()-1];

}

int main()
{
  int n = 4;
  vector<int> arr = {1,2,7};
  int sum = 10;
  cout << subsetSum(arr, sum, arr.size());
}