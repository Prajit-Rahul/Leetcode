class Solution {
public:
    int recc(vector<int>& nums, int sum, int ind, vector<vector<int>> &dp){
        if(ind == 0){
            if(sum == nums[ind] || sum == 0){
                if(nums[ind] == 0) return 2;
                return 1;
            }
            return 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int take = 0;
        if(sum-nums[ind]>=0)
            take = recc(nums, sum-nums[ind], ind-1, dp);
        int ntake = recc(nums, sum, ind-1, dp);
        return dp[ind][sum] = take + ntake;
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
    // int recc(vector<int>& nums, int target, int ind, vector<vector<int>> &dp){
    //     if(ind == 0){
    //         if(nums[ind] == 0 && target == 0) return 2;
    //         if(target == 0 || nums[ind] == target) return 1;
    //         return 0;
    //     }
    //     if(dp[ind][target] != -1) return dp[ind][target];
    //     int take = 0;
    //     if(target >= nums[ind])
    //         take += recc(nums, target-nums[ind], ind-1, dp);
    //     int ntake = recc(nums, target, ind-1, dp);
    //     return dp[ind][target] = take + ntake;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int sum = 0;
    //     for(auto &it: nums){
    //         sum += it;
    //     }
    //     sum -= target;
    //     if(sum < 0 || sum%2 != 0) return 0;
    //     sum /= 2;
    //     vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    //     return recc(nums, sum, n-1, dp);
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int sum = 0;
    //     for(auto &it: nums){
    //         sum += it;
    //     }
    //     sum -= target;
    //     if(sum < 0 || sum%2 != 0) return 0;
    //     sum /= 2;
    //     vector<vector<unsigned>> dp(n+1, vector<unsigned>(sum+1, 0));
    //     dp[0][0] = 1;
    //     if(sum >= nums[0]) dp[0][nums[0]] = 1;
    //     if(nums[0] == 0) dp[0][0] = 2;
    //     for(int ind=1; ind<n; ind++){
    //         for(int tar = 0; tar<=sum; tar++){
    //             if(tar >= nums[ind])
    //                 dp[ind][tar] += dp[ind-1][tar-nums[ind]];
    //             dp[ind][tar] += dp[ind-1][tar];
    //         }
    //     }
    //     return dp[n-1][sum];
    // }
};