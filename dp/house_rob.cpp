// class Solution {
// public:
//     // this is just the slightly modified verison of the max sum of non-adj 
    
// 	int f(int ind, vector<int> &nums, vector<int> &dp) {
// 		if (ind == 0) return nums[ind];

// 		if (ind < 0) return 0;
// 		// step2: check if it is present in the dp vector
// 		if (dp[ind] != -1) return dp[ind];

// 		// pick condition
// 		int pick = nums[ind] + f(ind - 2, nums, dp);

// 		// not-pick condition
// 		int n_pick = 0 + f(ind - 1, nums, dp);

// 		return dp[ind] = max(pick, n_pick);
// }

		
//     int rob(vector<int>& nums) {
// 	  int n = nums.size();
//       // step1: declare a vector named dp
// 	  vector<int> dp(n+1,-1);
//       // base condition
//       int mx = -1;
//       return max(mx,f(n-1,nums,dp));
        
//     }
// };