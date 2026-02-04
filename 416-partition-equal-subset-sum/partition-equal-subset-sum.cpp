class Solution {
public:
    // bool recc(vector<int> &nums, int ind, int sum, vector<vector<int>> &dp){
    //     if(ind == nums.size()){
    //         return false;
    //     }
    //     if(sum == 0) return true;
    //     if(dp[ind][sum] != -1) return dp[ind][sum];
    //     bool ntake = recc(nums, ind+1, sum, dp);
    //     bool take = false;
    //     if(sum >= nums[ind]) take = recc(nums, ind+1, sum-nums[ind], dp);
    //     return dp[ind][sum] = ntake || take;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0, n = nums.size();
    //     for(auto &it: nums){
    //         sum += it;
    //     }
    //     if(sum%2 != 0) return false;
    //     sum /= 2;
    //     vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
    //     return recc(nums, 0, sum, dp);
    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto &it: nums){
            sum += it;
        }
        if(sum%2 != 0) return false;
        sum /= 2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        for(int ind=n-1; ind>=0; ind--){
            for(int s=1; s<=sum; s++){
                bool ntake = dp[ind+1][s];
                bool take = false;
                if(s >= nums[ind]) take = dp[ind+1][s-nums[ind]];
                dp[ind][s] = ntake || take;
            }
        }
        return dp[0][sum];
    }
};