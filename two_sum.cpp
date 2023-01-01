#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> q;
        for(int i=0; i<nums.size(); i++){
            if(q.find(target-nums[i]) != q.end()){
                ans.push_back(q[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            q[nums[i]] = i;
        }
        return ans;


    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target;
    cin >> target;

    for(auto value : nums){
        cout << value << " ";
    }

    

    // Solution obj;
    // vector<int> res = obj.twoSum(nums,target);
    // for(int i=0; i<res; i++){
    //     cout << res[i] << endl;
    // } 

    return 0;

}
