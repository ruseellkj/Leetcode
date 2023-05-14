class Solution {
public:

    int f(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp) {
        // base case
        if (ind == 0) {
            return (tar % coins[0] == 0);
        }

        if (dp[ind][tar] != -1) return dp[ind][tar];

        long nottake = f(ind - 1, tar, coins, dp);
        long  take = 0;
        if (coins[ind] <= tar) take = f(ind, tar - coins[ind], coins, dp);

        return dp[ind][tar] = nottake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};