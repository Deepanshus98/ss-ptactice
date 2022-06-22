#include <bits/stdc++.h>
using namespace std;

int sumAtKthLevel(string tree, int k)
{
	int level = -1;
	int sum = 0;
	int n = tree.length();

	for (int i=0; i<n; i++)
	{
		
		if (tree[i] == '(')
			level++;

		
		else if (tree[i] == ')')
			level--;

		else
		{
			// check if current level is
			// the desired level or not
			if (level == k)
				sum += (tree[i]-'0');
		}
	}

	
	return sum;
}

// Driver program to test above
int main()
{
	string tree = "(0(5(6()())(4()(9()())))(7(1()())(3()())))";
	int k = 2;
	cout << sumAtKthLevel(tree, k);
	return 0;
}
    
