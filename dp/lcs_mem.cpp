class Solution {
public:
// naive recursive approach

    int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
        // base condition
        if (i < 0 || j < 0) return 0;

        // step2:
        if (dp[i][j] != -1) return dp[i][j];
        // if the characs are equal then move the pointers backward
        if (text1[i] == text2[j]) return 1 + f(i - 1, j - 1, text1, text2, dp);

        // if the characs are not matching then return the max of both
        return dp[i][j] = max(f(i, j - 1, text1, text2, dp), f(i - 1, j, text1, text2, dp));

    }


    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // step1: declare a 2d vector
        vector<vector<int>> dp(n + 1, vector<int> (m, -1));
        return f(n - 1, m - 1, text1, text2, dp);
    }
};