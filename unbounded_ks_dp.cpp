#include <bits/stdc++.h>

int f(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    //base case
    if (ind == 0) {
        if (wt[0] <= W)
        {
            return ((int)(W / wt[0])) * val[0];
        }
        else return 0;
    }

    if (dp[ind][W] != -1) return dp[ind][W];

    int notsteal = 0 + f(ind - 1, W, val, wt, dp);
    int steal = INT_MIN;
    if (wt[ind] <= W) {
        steal = val[ind] + f(ind, W - wt[ind], val, wt, dp);
    }

    return dp[ind][W] = max(notsteal, steal);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, profit, weight, dp);
}