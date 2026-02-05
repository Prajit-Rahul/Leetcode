class Solution {
public:
    int recc(vector<int>& nums, int target, int ind, vector<vector<int>> &dp){
        if(ind < 0){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int take = 0;
        if(target >= nums[ind])
            take += recc(nums, target-nums[ind], ind-1, dp);
        int ntake = recc(nums, target, ind-1, dp);
        return dp[ind][target] = take + ntake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto &it: nums){
            sum += it;
        }
        sum -= target;
        if(sum < 0 || sum%2 != 0) return 0;
        sum /= 2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return recc(nums, sum, n-1, dp);
    }
};