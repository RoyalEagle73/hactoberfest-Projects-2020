#include<bits/stdc++.h>
using namespace std;

string reverseString(string A)
{
    stack <char> s;
    int len = A.size();
    for(int i=0;i<len;i++)
    {
        s.push(A[i]);
    }
    string str;
    for(int i=0;i<len;i++)
    {
        char ch = s.top();
        str = str + ch;
        s.pop();
    }
    return str;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        string str;
        cin>>str;

	    cout<<reverseString(str)<<"\n";
    }
	return 0;
}
