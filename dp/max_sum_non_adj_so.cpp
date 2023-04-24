#include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums) {

	// Write your code here.
	int n = nums.size();
	int prev = nums[0];
	int prev2 = 0;

	for (int i = 1; i < n; i++) {
		int pick = nums[i];
		if (i > 1) pick += prev2;

		int not_pick = 0 + prev;

		int curi = max(pick, not_pick);
		prev2 = prev;
		prev = curi;

	}
	return prev;
}