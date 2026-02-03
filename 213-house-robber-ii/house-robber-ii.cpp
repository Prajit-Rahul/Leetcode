class Solution {
public:
    // int recc(vector<int> &nums, int n, vector<int> &dp){
    //     if(n < 0) return 0;
    //     if(dp[n] != -1) return dp[n];
    //     int take = recc(nums, n-1, dp);
    //     int ntake = recc(nums, n-2, dp) + nums[n];
    //     return dp[n] = max(take, ntake);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n == 1) return nums[0];
    //     vector<int> temp1, temp2;
    //     for(int i=0; i<n; i++){
    //         if(i != 0) temp1.push_back(nums[i]);
    //         if(i != n-1) temp2.push_back(nums[i]);
    //     }
    //     vector<int> dp(n,-1), dp1(n, -1);
    //     int f = recc(temp1, n-2, dp);
    //     int l = recc(temp2, n-2, dp1);
    //     return max(l,f);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n+1,0), dp2(n+1,0);
        for(int i=1; i<n; i++){
            int take = nums[i];
            if(i>=2) take += dp1[i-2];
            int ntake = 0;
            if(i>=1) ntake += dp1[i-1];
            dp1[i] = max(take, ntake);
        }
        for(int i=0; i<n-1; i++){
            int take = nums[i];
            if(i>=2) take += dp2[i-2];
            int ntake = 0;
            if(i>=1) ntake += dp2[i-1];
            dp2[i] = max(take, ntake);
        }
        return max(dp1[n-1], dp2[n-2]);
    }
};