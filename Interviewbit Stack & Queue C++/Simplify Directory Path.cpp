/* C++ program to simplify a Unix styled absolute path of a file */
#include <bits/stdc++.h>
using namespace std;
string simplify(string A)
{
	stack<string> st;
	string dir;
	string res;
	res.append("/");

	int len_A = A.length();

	for (int i = 0; i < len_A; i++)
    {
		dir.clear();
		// skip all the multiple '/' Eg. "/////""
		while (A[i] == '/')
			i++;

		// stores directory's name("a", "b" etc.)
		// or commands("."/"..") into dir
		while (i < len_A && A[i] != '/') {
			dir.push_back(A[i]);
			i++;
		}

		// if dir has ".." just pop the topmost element if the stack is not empty otherwise ignore.
		if (dir.compare("..") == 0)
        {
			if (!st.empty())
				st.pop();
		}

		// if dir has "." then simply continue with the process.
		else if (dir.compare(".") == 0)
			continue;

		// pushes if it encounters directory's name("a", "b").
		else if (dir.length() != 0)
			st.push(dir);
	}

	// a temporary stack (st1) which will contain the reverse of original stack(st).
	stack<string> st1;
	while (!st.empty()) {
		st1.push(st.top());
		st.pop();
	}

	// the st1 will contain the actual res.
	while (!st1.empty()) {
		string temp = st1.top();

		// if it's the last element no need to append "/"
		if (st1.size() != 1)
			res.append(temp + "/");
		else
			res.append(temp);

		st1.pop();
	}

	return res;
}

// Driver code.
int main()
{
	// string str("/a/./b/../../c/");
	int t;
	while(t--)
    {
        string str;
        cin>>str;
        string res = simplify(str);
	    cout << res<<"\n";
    }
	return 0;
}
