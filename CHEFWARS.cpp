/* Problem Code : CHEFWARS */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int h,p;
		cin >> h >> p;
		while((h!=0) && (p!=0))
		{
			h = h-p;
			if(h <= 0 && p>0)
			{
				cout << 1 << endl;
				break;
			}
			p = p/2;
			if(h>p && p<1)
				cout << 0 << endl;
		}
	}
	return 0;
}