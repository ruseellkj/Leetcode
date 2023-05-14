#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int> &num, int tar)
{
	// Write your code here.
	int n = num.size();
	// step1: to declare a dp vector
	vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

	for (int i = 0; i < n; i++) dp[i][0] = 1;
	if (num[0] <= tar) dp[0][num[0]] = 1;

	for (int ind = 1; ind < n; ind++) {
		for (int sum = 0; sum <= tar; sum++) {
			int not_pick = dp[ind - 1][sum];
			int pick = 0;
			if (num[ind] <= sum) pick = dp[ind - 1][sum - num[ind]];

			dp[ind][sum] = pick + not_pick;
		}
	}

	return dp[n - 1][tar];

}