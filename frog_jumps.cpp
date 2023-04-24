#include <bits/stdc++.h>
using namespace std;


int f(int ind, vector<int> &heights, vector<int> &dp) {
    if (ind == 0) return 0;

    if (dp[ind] != -1) return dp[ind];

    int l = f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int r = INT_MAX;
    if (ind > 1)
        r = f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);


    return dp[ind] = min(l, r);
}
int frogJump(int n, vector<int> &heights)

{


#ifndef ONLINE_JUDGE
    // for getting the input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing the output at output/txt
    freopen("output.txt", "w", stdout);
#endif


    // Write your code here.
    vector<int> dp(n + 1, -1);
    return f(n - 1, heights, dp);

}