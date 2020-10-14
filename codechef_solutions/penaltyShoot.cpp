/*Teams A and B are having a penalty shoot-out to decide the winner of their football match. Each team gets to take a shot N times, and the team with the higher number of scored goals at the end wins. If the number of goals scored during the shoot-out by each team turns out to be the same even after all 2N shots, then they stop and agree that the result is a draw.

The two teams take shots alternately — team A shoots first, then team B shoots, then team A and so on until team B takes its N-th shot (at which point each team has taken exactly N shots). Even though all 2N shots are taken, the result of the shoot-out is often known earlier — e.g. if team A has already scored N-1 goals and team B has missed at least two shots, team A is definitely the winner.

For each shot, you know whether it was a goal or a miss. You need to find the earliest moment when the winner is known — the smallest s (0=s=2N) such that after s shots, the result of the shoot-out (whether team A won, team B won or the match is drawn) would be known even if we did not know the results of the remaining 2N-s shots.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains a string S with length 2·N, where for each valid i, the i-th character is '0' if the i-th shot was a miss or '1' if it was a goal.
Output
For each test case, print a single line containing one integer — the smallest s such that after s shots, the result of the shoot-out is known.

Constraints
1=T=105
1=N=105
S contains only characters '0' and '1'
the sum of N over all test cases does not exceed 106
Example Input
2
3
101011
3
100001
Example Output
4
6
Explanation
Example case 1: After four shots, team A has scored 2 goals and team B has scored 0 goals. Whatever happens afterwards, team A is guaranteed to win, since even if team B scored their last (and only) goal and team A did not score their last goal, team A would still win by 1 goal.

Example case 2: Team A scores the first goal and after that, neither team scores any goals until the last shot. Up till then, there is always a possibility that the match could end in a draw if team B scored a goal with its last shot, or in the victory of team A if it was a miss. We can only guarantee the result after the last shot.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    for(int i=0;i<t;i++)
    {
       cin>>n;
       cin>>s;
       long long int ra=n,rb=n;
       long long int cntA=0,cntB=0;
       long long int answer=2*n;
       long long int j;
      for( j=1;j<=2*n;j++)
      {
         if(j%2==0)
         {
             if(s[j-1]=='1')
             {
             cntB++;
             rb--;}
             else 
             rb--;
         }
         else 
         {
             if(s[j-1]=='1')
             {
             cntA++;
             ra--;
             }
             else 
             ra--;
         }
         if(rb<(cntA-cntB))
           {answer=j;break;}
         if(ra<(cntB-cntA))
            {answer=j;break;}
         
      } 
      cout<<answer<<endl;
       
    }
}
