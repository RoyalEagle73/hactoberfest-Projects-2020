/* Problem Code : HORSES */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,ans = 0,i,j;
		cin >> n;
		int s[n];
		for(i=0;i<n;i++)
		{
			cin >> s[i];
		}
		int len = sizeof(s)/sizeof(s[0]);
		sort(s,s+len,greater<int>());
		int min1 = INT_MAX;
		for(i=0;i<n-1;i++)
		{
			ans = s[i] - s[i+1];
			if(ans < min1)
				min1 = ans;
		}
		cout << min1 << endl;
	}
	return 0;
}