#include<bits/stdc++.h>
using namespace std;

vector <int> printKMax( vector <int> &A ,int k)
{
    int n = A.size();
	deque<int> Qi(k);
	vector <int> v;
	int i;
	for (i = 0; i < k; ++i)
	{
		while ( (!Qi.empty()) && A[i] >= A[Qi.back()])
			Qi.pop_back();

		Qi.push_back(i);
	}
	// Process rest of the elements, i.e., from arr[k] to arr[n-1]
	for ( ; i < n; ++i)
	{

		v.push_back(A[Qi.front()]);

		while ( (!Qi.empty()) && Qi.front() <= i - k)
			Qi.pop_front();

		while ( (!Qi.empty()) && A[i] >= A[Qi.back()])
			Qi.pop_back();

		Qi.push_back(i);
	}

	// Print the maximum element of last window
	v.push_back(A[Qi.front()]);

	return v;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n,val,k;
        cin>>n>>k;
        vector <int> A;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            A.push_back(val);
        }

	    A = printKMax(A,k);
	    for(int i=0;i<n-k+1;i++)
            cout<<A[i]<<" ";
        cout<<"\n";
    }
	return 0;
}
