class Solution {
public:
    int recc(vector<int> &nums, int n, vector<int> &dp){
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int take1 = recc(nums, n-1, dp);
        int take2 = recc(nums, n-2, dp) + nums[n];
        return dp[n] = max(take1, take2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return recc(nums, n-1, dp);
    }
};