class Solution {
public:
    int recc(vector<int>& nums, int ind, int sum, vector<vector<int>> &dp){
        if(ind <= 0){
            if(nums[ind] == 0 && sum == 0) return 2;
            if(sum == 0 || sum == nums[ind]) return 1;
            return 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int take = (sum-nums[ind]>=0)?recc(nums, ind-1, sum-nums[ind], dp):0;
        int ntake = recc(nums, ind-1, sum, dp);
        return dp[ind][sum] = take + ntake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        sum = sum - target;
        if(sum < 0 || sum%2!=0) return 0;
        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return recc(nums, n-1, sum, dp);
    }
};