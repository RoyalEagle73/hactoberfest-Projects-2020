/* Problem Code : LINCHESS */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int n,k,ans = INT_MAX;
		cin >> n >> k;
		long long int p[n],i;
		for(i=0;i<n;i++)
		{
			cin >> p[i];
		}
		sort(p,p+n);
		for(i=0;i<n;i++)
		{
			if(k % p[i] == 0)
				ans = p[i];
		}
		if(ans < INT_MAX)
			cout << ans << endl;
		if(ans == INT_MAX)
			cout << -1 << endl;
	}
	return 0;
}