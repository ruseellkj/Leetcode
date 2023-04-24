#include <bits/stdc++.h>
using namespace std;


int f(int ind, vector<int> &heights, vector<int> &dp)
{
	// base condition
	if (ind == 0) return 0;

	if (dp[n] != -1) return dp[n];

	int min_steps = INT_MAX;

	for (int j = 1; j <= k ; j++) {
		if (ind - j >= 0) {
			int jump = f(ind - j) + abs(heights[ind] - heights[ind - j]);
			min_steps = min(min_steps, jump);

		}
	}
	return dp[n] = min_steps;
}


int frogJump(int n, vector<int> &heights)

{


#ifndef ONLINE_JUDGE
	// for getting the input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing the output at output/txt
	freopen("output.txt", "w", stdout);
#endif


	// Write your code here.
	vector<int> dp(n + 1, -1);
	return f(n - 1, heights, dp);

}