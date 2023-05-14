class Solution {
public:

    int f(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp) {
        // method 1: by using recursion
        // base case
        if (ind == 0) {
            if (tar % coins[0] == 0) return tar / coins[0];
            // to avoid overflow or else 1e9
            return  1e9;
        }

        // step2:
        if (dp[ind][tar] != -1) return dp[ind][tar];

        int nottake = 0 + f(ind - 1, tar, coins, dp);
        int take = INT_MAX;
        if (coins[ind] <= tar) {
            take = 1 + f(ind, tar - coins[ind], coins, dp);
        }

        return dp[ind][tar] = min(nottake, take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // step1: declare a vector/arr dp
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        if (ans >= 1e9)
            return -1;
        return ans;


    }
};