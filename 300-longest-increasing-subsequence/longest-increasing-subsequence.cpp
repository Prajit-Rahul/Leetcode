class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<unsigned>> dp(n+1, vector<unsigned> (n+1, 0));
        for(int ind=n-1; ind>=0; ind--){
            for(int prev=ind-1; prev>=-1; prev--){
                int take = 0;
                if(prev == -1 || nums[ind] > nums[prev])
                    take = 1 + dp[ind+1][ind+1];
                int ntake = dp[ind+1][prev+1];
                dp[ind][prev+1] = max(take, ntake);
            }
        }
        return dp[0][0];
    }
    // int recc(vector<int> &nums, int ind, int prev, vector<vector<int>> &dp){
    //     if(ind == nums.size()) return 0;
    //     if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
    //     int ntake = recc(nums, ind+1, prev, dp);
    //     int take = INT_MIN;
    //     if(prev == -1 || nums[ind] > nums[prev]) take = 1 + recc(nums, ind+1, ind, dp);
    //     return dp[ind][prev+1] = max(take, ntake);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    //     return recc(nums, 0, -1, dp);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    //     for(int ind=n-1; ind>=0; ind--){
    //         for(int prev = ind-1; prev >= -1; prev--){
    //             int ntake = dp[ind+1][prev+1];
    //             int take = INT_MIN;
    //             if(prev == -1 || nums[ind] > nums[prev]) take = 1 + dp[ind+1][ind+1];
    //             dp[ind][prev+1] = max(take, ntake);
    //         }
    //     }
    //     return dp[0][0];
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> curr(n+1, 0), next(n+1, 0);
    //     for(int ind=n-1; ind>=0; ind--){
    //         for(int prev = ind-1; prev >= -1; prev--){
    //             int ntake = next[prev+1];
    //             int take = INT_MIN;
    //             if(prev == -1 || nums[ind] > nums[prev]) take = 1 + next[ind+1];
    //             curr[prev+1] = max(take, ntake);
    //         }
    //         next = curr;
    //     }
    //     return next[0];
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n+1, 1);
    //     for(int ind=0; ind<n; ind++){
    //         for(int prev=0; prev<ind; prev++){
    //             if(nums[ind] > nums[prev]){
    //                 dp[ind] = max(dp[ind], dp[prev] + 1);
    //             }
    //         }
    //     }
    //     return *max_element(dp.begin(), dp.end());
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> temp;
    //     int maxi = 0;
    //     for(int ind=0; ind<n; ind++){
    //         if(ind == 0 || temp.back() < nums[ind]){
    //             temp.push_back(nums[ind]);
    //             maxi++;
    //         }
    //         else{
    //             auto it = lower_bound(temp.begin(), temp.end(), nums[ind]);
    //             *it = nums[ind];
    //         }
    //     }
    //     return maxi;
    // }
};