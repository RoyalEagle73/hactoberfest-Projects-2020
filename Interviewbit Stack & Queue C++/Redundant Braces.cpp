#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool braces(string A)
{
    stack <char> s;
    int len = A.size();
    char ch;
    for(int i=0;i<len;i++)
    {
        ch = A[i];
        if(ch==')')
        {
            char tp = s.top();
            s.pop();

            bool ans = true;

            while(tp != '(')
            {
                if(tp=='+' || tp=='-' || tp=='*' || tp=='/')
                    ans = false;
                tp = s.top();
                s.pop();
            }
            if(ans == true)
                return true;
        }
        else
            s.push(ch);
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        //Check Expression contains redundant bracket or not
        braces(str)?cout<<"Yes\n" : cout<<"No\n";
    }
    return 0;
}
