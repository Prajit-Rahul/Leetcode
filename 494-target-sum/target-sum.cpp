class Solution {
public:
    // int recc(vector<int>& nums, int ind, int sum, vector<vector<int>> &dp){
    //     if(ind <= 0){
    //         if(nums[ind] == 0 && sum == 0) return 2;
    //         if(sum == 0 || sum == nums[ind]) return 1;
    //         return 0;
    //     }
    //     if(dp[ind][sum] != -1) return dp[ind][sum];
    //     int take = (sum-nums[ind]>=0)?recc(nums, ind-1, sum-nums[ind], dp):0;
    //     int ntake = recc(nums, ind-1, sum, dp);
    //     return dp[ind][sum] = take + ntake;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int sum = 0;
    //     int n = nums.size();
    //     for(int i=0; i<nums.size(); i++){
    //         sum += nums[i];
    //     }
    //     sum = sum - target;
    //     if(sum < 0 || sum%2!=0) return 0;
    //     sum /= 2;
    //     vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    //     return recc(nums, n-1, sum, dp);
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        sum = sum - target;
        if(sum < 0 || sum%2!=0) return 0;
        sum /= 2;
        vector<vector<unsigned>> dp(n, vector<unsigned>(sum+1, 0));
        dp[0][0] = 1;
        if(sum >= nums[0]) dp[0][nums[0]] = 1;
        if(nums[0] == 0) dp[0][0] = 2;
        for(int ind=1; ind<n; ind++){
            for(int s=0; s<=sum; s++){
                dp[ind][s] += (s-nums[ind]>=0)?dp[ind-1][s-nums[ind]]:0;
                dp[ind][s] += dp[ind-1][s];
            }
        }
        return dp[n-1][sum];
    }
};