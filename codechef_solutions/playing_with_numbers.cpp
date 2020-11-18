//question link
//https://www.codechef.com/problems/SJ1

//my solution

#include <bits/stdc++.h>
#define ll long long
using namespace std;

 bool visit[100000+5];
 vector<ll>adj[100000+5];
 ll arr[100000+5];
 ll mod[100000+5];
 ll gcd[100000+5];

ll gcdd(ll a,ll b)
{
    if(a==0)
    return b;
    else if(b==0)
    return a;
    else
    return gcdd(b,a%b);
}

void dfs(ll par,ll node)
{
    if(par==0)
    {
        gcd[node]=arr[node];
        visit[node]=true;
    }
    else
    {
        gcd[node]=gcdd(arr[node],gcd[par]);
        visit[node]=true;
    }
    ll i;
    for(i=0;i<adj[node].size();i++)
    {
        ll t=adj[node][i];
        if(!visit[t])
        {
            dfs(node,t);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,i,a,b,j;
	    cin>>n;
	    for(i=1;i<=n+1;i++)
	    adj[i].clear();
	    for(i=1;i<n;i++)
	    {
	        cin>>a>>b;
	        adj[a].push_back(b);
	        adj[b].push_back(a);
	    }
	    for(i=1;i<=n;i++)
	    cin>>arr[i];
	    for(i=1;i<=n;i++)
	    {
	        cin>>mod[i];
	        visit[i]=false;
	    }
	    dfs(0,1);
	    for(i=2;i<=n;i++)
	    {
	        if(adj[i].size()==1)
	        {
	            //gcd[i]%=mod[i];
	            a=gcdd(mod[i],gcd[i]);
	            cout<<max((mod[i])-a,gcd[i])%mod[i]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
