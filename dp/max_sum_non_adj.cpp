#include <bits/stdc++.h>
using namespace std;


int f(int ind, vector<int> &nums) {
    //base condition
    if (ind == 0) return nums[ind];

    if (ind < 0) return 0;

    // pick condition
    int pick = nums[ind] + f(ind - 2, nums);

    // not-pick condition
    int n_pick = 0 + f(ind - 1, nums);

    return max(pick, n_pick);
}

int maximumNonAdjacentSum(vector<int> &nums) {

    // Write your code here.
    int n = nums.size();
    return f(n - 1, nums);
}