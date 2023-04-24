#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &nums, vector<int> &dp) {
	if (ind == 0) return nums[ind];

	if (ind < 0) return 0;
	// step2: check if it is present in the dp vector
	if (dp[ind] != -1) return dp[ind];

	// pick condition
	int pick = nums[ind] + f(ind - 2, nums, dp);

	// not-pick condition
	int n_pick = 0 + f(ind - 1, nums, dp);

	return dp[ind] = max(pick, n_pick);
}

int maximumNonAdjacentSum(vector<int> &nums) {

	// Write your code here.
	// step1: declare the dp
	// vector<int> dp(n, -1);
	int n = nums.size();
	vector<int> dp(n + 1, -1);
	return f(n - 1, nums, dp);
}