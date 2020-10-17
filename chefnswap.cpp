// https://www.codechef.com/problems/CHFNSWAP (question link, this question was asked on september long challenge)

#include <iostream>
using namespace std;
long long int bsearch(long long int a, long long int s, long long int e, bool &x)
{
    long long int mid;

    while(s<=e)
    {
        mid=(s+e)/2;
        if((mid*(mid+1))/2==a)
        {   
            x=true;
            return mid;
        }
        else if((mid*(mid+1))/2<a)
        s=mid+1;
        else
        e=mid-1;
    }
    if((mid*(mid+1))/2<a)
    return mid;
    else
    return mid-1;
}
int main() {
	// your code goes here
    int t;
    long long int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long int a=(n*(n+1))/2;
        if(a&1)
        cout<<0<<endl;
        else
        {
            long long int k=0,s=n;
            bool x=false;
            long long int b=bsearch(a/2,n/2,n,x);
            if(x==false)
            cout<<n-b<<endl;
            else
            cout<<(b*(b-1))/2+((n-b)*(n-b-1))/2+n-b<<endl;
        }
    }
	return 0;
}
