#include <bits/stdc++.h>
using namespace std;

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
	// base case
	if (target == 0) return true;
	if (ind == 0) return (arr[0] == target);

	// step2:
	if (dp[ind][target] != -1) return dp[ind][target];

	// not take condition
	bool nottake = f(ind - 1, target, arr, dp);

	// take condition
	bool take = false;
	// only if the target is greater than the curr element of the arr
	if (target >= arr[ind]) {
		take = f(ind - 1, target - arr[ind], arr, dp);
	}

	return dp[ind][target] = take | nottake;

}

bool isSubsetSum(vector<int>arr, int sum) {
	// code here
	// step1: create a array/vector named as dp
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
	return f(n - 1, sum, arr, dp);
}


