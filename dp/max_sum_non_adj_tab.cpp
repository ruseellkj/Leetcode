#include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums) {

	// Write your code here.
	// step1: declare the dp vector
	vector<int> dp(n + 1, -1);

	// base condition
	dp[0] = nums[0];
	int neg = 0;
	int n = nums.size();


	for (int i = 1; i < n; i++) {
		int pick = nums[i]; if (i > 1) pick += dp[i - 2];
		int not_pick = 0 + dp[i - 1];

		dp[i] = max(pick, not_pick);

	}
	return dp[n - 1]
}