class Solution {
public:

    // int f(int i, int j, string s, string t, vector<vector<int>> &dp)
    // {
    //     // base case
    //     if(i == 0) return j;
    //     if(j == 0) return i;

    //     if(dp[i][j] != -1) return dp[i][j];
    //     // if the strings are matching
    //     if(s[i-1] == t[j-1]){
    //         return f(i-1,j-1,s,t,dp);
    //     }

    //     // if they are not matching
    //     return dp[i][j] = 1 + min(f(i,j-1,s,t,dp),
    //                             min(f(i-1,j,s,t,dp) ,
    //                                 f(i-1,j-1,s,t,dp)));

    // }

    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int j = 0; j <= m; j++) dp[0][j] = i;
        for (int i = 0; j <= n; j++) dp[i][0] = j;

        for (int i = 1 ; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) return dp[i - 1][j - 1];

                // if they are not matching
                dp[i][j] = 1 + min(dp[i][j - 1],
                                   min(dp[i - 1][j],
                                       dp[i - 1][j - 1]));

                return dp[n][m];
            }
        }
    }
};