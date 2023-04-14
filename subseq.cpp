class Solution
{
public:
    void subseq(int ind, vector<int> &ds, vector<int> &nums, vector<vector<int>> &res)
    {
        if (ind >= nums.size())
        {
            res.push_back(ds);
            return;

            if (ds.size() == 0)
            {
                res.push_back(ds);
                return;
            }
        }

        // add the element from the nums vector -- take condition
        ds.push_back(nums[i]);
        // call for the next index
        subseq(ind + 1, ds, nums, res);
        // after getting [3,1,2] i want [3,1] then remove the last index element
        ds.pop_back();
        // not pick or not take condition
        subseq(ind + 1, ds, nums, res);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        // this qs can be done by recursion
        // for storing the res
        vector<vector<int>> res;
        // for storing the subsets or subsequence
        vector<int> ds;
        subseq(0, ds, nums, res);
        return res;
    }
};