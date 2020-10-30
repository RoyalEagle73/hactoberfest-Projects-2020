#include<bits/stdc++.h>
using namespace std;

/*The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.*/
int isValid(string A) {
    stack <char> s;
    int len = A.size();
    int c=0;
    for(int i=0;i<len;i++){
        if(A[i]=='[' || A[i]=='{' || A[i]=='(')
        {
            s.push(A[i]);
            c++;
        }
        else if(!s.empty() && A[i]=='}' && s.top()=='{')
        {
            s.pop();
            c--;
        }
        else if(!s.empty() && A[i]==']' && s.top()=='[')
        {
            s.pop();
            c--;
        }
        else if(!s.empty() && A[i]==')' && s.top()=='(')
        {
            s.pop();
            c--;
        }
        else
            return 0;
    }
    if(c==0)
       return 1;
    else
       return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        string str;
        cin>>str;

	    if(isValid(str))
	        cout<<"Valid String\n";
        else
            cout<<"InValid String\n";
    }
	return 0;
}
