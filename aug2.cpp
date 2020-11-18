#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
long long  t,n,k,s;
cin>>t;
while(t--){
    cin>>n>>k;
    ll p[n];
    ll ans=INT_MAX;
    ll a=-1;
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(k%p[i]==0){
            if(k/p[i]<ans){
                ans=k/p[i];
                a=p[i];
            }
        }
    }
    cout<<a<<endl;

    }
return 0;
}
