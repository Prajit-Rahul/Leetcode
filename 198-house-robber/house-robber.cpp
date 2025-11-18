class Solution {
public:
    int recc(vector<int>& nums, int ind, vector<int> &dp){
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int take = recc(nums, ind-2, dp) + nums[ind];
        int ntake = recc(nums, ind-1, dp);
        return dp[ind] = max(take, ntake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recc(nums, n-1, dp);
    }
};