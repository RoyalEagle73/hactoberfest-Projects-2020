/* Problem Code : JOHNY */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,ans = 0;
	cin >> t;
	while(t--)
	{
		long long int n;
		cin >> n;
		long long int a[n],i;
		for(i=0;i<n;i++)
		{
			cin >> a[i];
		}
		long long int k,store;
		cin >> k;
		store = a[k-1];
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			if(a[i] == store)
				ans = i;
		}
		cout << ans+1 << endl;
	}
	return 0;
}