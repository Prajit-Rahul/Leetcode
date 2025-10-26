class Solution {
public:

    // int recc(vector<int> &nums, int i, vector<int> &dp){
    //     if(i >= nums.size()) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int p = recc(nums, i+2, dp) + nums[i];
    //     int np = recc(nums, i+1, dp);
    //     return dp[i] = max(p, np);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            int take = nums[i];
            if(i-2>=0) take += dp[i-2];
            int ntake = dp[i-1];
            dp[i] = max(take, ntake);
        }
        return dp[n-1];
    }
};