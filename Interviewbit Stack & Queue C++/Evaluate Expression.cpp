/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
input  = [ "2", "3", "+", "4", "-" ] output:- 1
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <string>
int evalRPN(vector<string> A)
{
    stack <string> s;
    for (int i=0; i<A.size(); i++)
    {
        if(A[i]=="+" || A[i]=="-" || A[i]=="*" || A[i]=="/")
        {
            int num1 = stoi(s.top());
            s.pop();
            int num2 = stoi(s.top());
            s.pop();
            int ans;
            if(A[i]=="+")
                ans = num2 + num1;
            if(A[i]=="-")
                ans = num2 - num1;
            if(A[i]=="*")
                ans = num2 * num1;
            if(A[i]=="/")
                ans = num2 / num1;

            string st = to_string(ans);
            s.push(st);

        }
        else
            s.push(A[i]);
    }
    int num = stoi(s.top());
    return num;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <string> v;
        string str;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            v.push_back(str);
        }

        cout<<evalRPN(v)<<"\n";
    }
    return 0;
}
