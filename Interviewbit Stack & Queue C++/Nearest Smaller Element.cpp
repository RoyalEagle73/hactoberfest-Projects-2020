// C++ implementation of efficient algorithm to find smaller element on left side
#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
	stack<int> S;
	vector <int> v;
    int n = A.size();
	// Traverse all array elements
	for (int i=0; i<n; i++)
	{
		while (!S.empty() && S.top() >= A[i])
			S.pop();

		// If all elements in S were greater than arr[i]
		if (S.empty())
			v.push_back(-1);
		else //Else print the nearest smaller element
			v.push_back(S.top());

		S.push(A[i]);
	}
	return v;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n,val;
        cin>>n;
        vector <int> A;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            A.push_back(val);
        }

	    A = prevSmaller(A);
	    for(int i=0;i<n;i++)
            cout<<A[i]<<" ";
        cout<<"\n";
    }
	return 0;
}
