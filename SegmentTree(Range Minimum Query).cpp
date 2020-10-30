//SegmentTree(Range Minimum Query):-https://practice.geeksforgeeks.org/problems/range-minimum-query/1

#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends

void cons(int seg[],int a[],int index,int st,int end){
    if(st==end){
        seg[index]=a[st];
        return;
    }
    else{
        int mid=(st+end)/2;
        cons(seg,a,2*index+1,st,mid);
        cons(seg,a,2*index+2,mid+1,end);
        seg[index]=min(seg[2*index+1],seg[2*index+2]);
        
    }
}
/* The functions which 
builds the segment tree */
int *constructST(int arr[],int n)
{
    int n1=2*n+2;
  int seg[n1]={0};
  cons(seg,arr,0,0,n-1);
  for(int i=0;i<n1;i++){
      cout<<seg[i]<<" ";
  }
  return seg;
}

int Range(int st[],int s,int e,int index,int l,int r){
    if(s>r || e<l)
       return INT_MAX;
    else if(s>=l && e<=r)
       return st[index];
   else{
       int m=(s+e)/2;
       int l1=Range(st,s,m,2*index+1,l,r);
       int r1=Range(st,m+1,e,2*index+2,l,r);
       return min(l1,r1);

       
   }
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
   return Range(st,0,n-1,0,a,b);
}
