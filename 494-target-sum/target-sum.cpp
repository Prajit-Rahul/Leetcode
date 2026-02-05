class Solution {
public:
    int recc(vector<int>& nums, int target, int ind, vector<vector<int>> &dp){
        if(ind == 0){
            if(nums[ind] == 0 && target == 0) return 2;
            if(target == 0 || nums[ind] == target) return 1;
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
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int sum = 0;
    //     for(auto &it: nums){
    //         sum += it;
    //     }
    //     sum -= target;
    //     if(sum < 0 || sum%2 != 0) return 0;
    //     sum /= 2;
    //     vector<vector<unsigned>> dp(n+2, vector<unsigned>(sum+1, 0));
    //     for(int ind=1; ind<=n; ind++){
    //         for(int tar = 0; tar<=sum; tar++){
                
    //         }
    //     }
    //     return dp[n][sum];
    // }
};