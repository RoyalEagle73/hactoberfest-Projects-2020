// https://www.codechef.com/problems/ADAKNG (link to the problem)
code:
  
  #include <iostream>
using namespace std;

int main() {
	// your code goes here
    int t,r,c,k;
    cin>>t;
    while(t--)
    {
        int ud=0,lr=0;
        cin>>r>>c>>k;
        if(c-k>0)
        lr+=k;
        else
        lr+=(c-1);
        if(c+k<9)
        lr+=k;
        else
        lr+=(8-c);
        if(r-k>0)
        ud+=k;
        else
        ud+=(r-1);
        if(r+k<9)
        ud+=k;
        else
        ud+=(8-r);
        cout<<(lr+1)*(ud+1)<<endl;
    }
	return 0;
}
