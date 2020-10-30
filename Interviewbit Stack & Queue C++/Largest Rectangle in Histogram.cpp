// C++ program to find maximum rectangular area in linear time
#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector <int> hist)
{
    int n = hist.size();
	// Create an empty stack. The stack holds indexes of hist[] array. The bars stored in stack are always in increasing order of their heights.
	stack<int> s;

	int max_area = 0; // Initalize max area
	int tp; // To store top of stack
	int area_with_top; // To store area with top bar as the smallest bar

	// Run through all bars of given histogram
	int i = 0;
	while (i < n)
	{
		// If this bar is higher than the bar on top stack, push it to stack
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);
		else
		{
			tp = s.top(); // store the top index
			s.pop(); // pop the top

			// Calculate the area with hist[tp] stack as smallest bar
			area_with_top = hist[tp] * ( s.empty() ? i : i - s.top() - 1 );

			// update max area, if needed
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	// Now pop the remaining bars from stack and calculate
	// area with every popped bar as the smallest bar
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n,val;
        cin>>n;
        vector <int> hist;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            hist.push_back(val);
        }

	    cout <<getMaxArea(hist)<<"\n";
    }
	return 0;
}
