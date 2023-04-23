#include <bits/stdc++.h>
using namespace std;


// each order should be in sorted order
// and
// and all the orders must be lexicographically sorted
// no repititions allowed that means only each number can be taken only once
// arr and target is given to us
class Solution {
public:

	void PrintC(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
		if (target == 0) {
			ans.push_back(ds);
			return;
		}

		// looping for 0th, 1th, 2nd,.....
		for (int i = ind; i < arr.size(); i++) {
			if (i > ind && arr[i] == arr[i - 1]) continue;
			if (arr[i] > target) break;
			ds.push_back(arr[i]);
			PrintC(i + 1, target - arr[i], arr, ans, ds);
			ds.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		// solution learnt from striver
		// as we want the combination in sorted order
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> ds;
		PrintC(0, target, candidates, ans, ds);
		return ans;
	}
};