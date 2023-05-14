#include <bits/stdc++.h>

int f(int ind, int sum, vector<int> &num, vector<vector<int>> &dp) {

  // base case
  if (ind == 0)
  {
    if (sum == 0 && arr[0] == 0) return 2;
    if (sum == 0 || sum == arr[0]) return 1;
    return 0;
  }

  // step2:
  if (dp[ind][sum] != -1) return dp[ind][sum];

  int not_pick = f(ind - 1, sum, num, dp);
  int pick = 0;
  if (num[ind] <= sum) pick = f(ind - 1, sum - num[ind], num, dp);

  return dp[ind][sum] = pick + not_pick;
}

int findWays(vector<int> &num, int tar)
{
  // Write your code here.
  int n = num.size();
  // step1: to declare a dp vector
  vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

  return f(n - 1, tar, num, dp);

}