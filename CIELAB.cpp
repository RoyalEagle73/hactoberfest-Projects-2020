/* Problem Code : CIELAB */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int a,b,ans = 0;
	cin >> a >> b;
	long long int ans1 = a-b;
	if(ans1 < 2)
		ans = ans1 + 1;
	else if(ans1%10 != 0)
		ans = ans1 - 1;
	else
		ans = ans1 + 1;
	cout << ans << endl;
	return 0;
}