#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vi g[N];
int a[N];
/*
int first(vector<int> v, int low , int high, int x, int n){
  if(high>=low){
    int mid=low+(high-low)/2;
    if((mid==n-1 || x>v[mid-1]) && v[mid]==x)
    return mid;
    else if(x>v[mid])
    return first(v, (mid+1), high, x,n);
    else
    return first(v, low, (mid-1), x, n);
  }
  return -1;
}
int last(vector<int> v, int low , int high, int x, int n){
  if(high>=low){
    int mid=low+(high-low)/2;
    if((mid==n-1 || x<v[mid+1]) && v[mid]==x)
    return mid;
    else if(x<v[mid])
    return last(v, low, (mid-1), x,n);
    else
    return last(v, (mid+1), high, x, n);
  }
  return -1;
} */

void solve() {
    int n;
    cin>>n;
    int a[n+1];
    a[1]=2, a[2]=3, a[3]=1, a[4]=5, a[5]=4;
    if(n!=1&&(n & (n-1))==0){
      cout<<"-1"<<"\n";
    }else{
      if(n==1){
        cout<<"1"<<"\n";
      }else if(n==2){
        cout<<"2 "<<"1"<<"\n";
      }else{
        if(n<=5){
          for(int i=1; i<=n; i++){
            cout<<a[i]<<" ";
          }
          cout<<"\n";
        }else{
          int j;
          for(j=6; j<=n; j++){
            if((j&(j-1))==0){
              a[j]=j+1;
              a[j+1]=j;
              j+=1;
            }else{
              a[j]=j;
            }
          }
          for(int k=1; k<=n; k++){
            cout<<a[k]<<" ";
          }
          cout<<"\n";
        }
      }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}