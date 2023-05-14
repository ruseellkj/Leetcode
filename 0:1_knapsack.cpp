//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:

    int f(int ind , int W, int wt[], int val[], vector<vector<int>> &dp) {
        // base case
        if (ind == 0) {
            // if we are at the last index and have capacity to steal then do it
            if (wt[ind] <= W) return val[0];
            return 0;
        }
        // step2:
        if (dp[ind][W] != -1 ) return dp[ind][W];

        int not_steal = 0 + f(ind - 1, W, wt, val, dp);

        // initially keeping the steal as INT_MIN
        int steal = INT_MIN;
        if (wt[ind] <= W) steal = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);

        return dp[ind][W] = max(not_steal, steal);



    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        // recursion method
        //  step1: declare a dp vector/arr
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, W, wt, val, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;

    }
    return 0;
}
// } Driver Code Ends
