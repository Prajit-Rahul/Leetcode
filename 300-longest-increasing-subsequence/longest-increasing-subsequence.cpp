class Solution {
public:
    int recc(vector<int> &nums, int ind, int prev, vector<vector<int>> &dp){
        if(ind >= nums.size()){
            return 0;
        }
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int ntake = recc(nums, ind+1, prev, dp);
        int take = INT_MIN;
        if(prev == -1 || nums[ind]>nums[prev]) take = 1 + recc(nums, ind+1, ind, dp);
        return dp[ind][prev+1] = max(take, ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recc(nums, 0, -1, dp);
    }
};