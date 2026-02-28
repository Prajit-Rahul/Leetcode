class Solution {
public:
    int recc(vector<int> &nums, int ind, vector<int> &dp){
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int take = recc(nums, ind-1, dp);
        int ntake = recc(nums, ind-2, dp) + nums[ind];
        return dp[ind] = max(take, ntake);
    }
    int rob(vector<int>& nums) {
        vector<int> temp;
        vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
        if(1 == nums.size()) return nums[0];
        for(int i=1; i<nums.size(); i++){
            temp.push_back(nums[i]);
        }
        int res1 = recc(temp, temp.size()-1, dp1);
        nums.pop_back();
        int res2 = recc(nums, nums.size()-1, dp2);
        return max(res1, res2);
    }
};