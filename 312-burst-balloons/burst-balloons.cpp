class Solution {
public:
    int recc(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k=i; k<=j; k++){
            ans = max(ans, nums[i-1] * nums[k] * nums[j+1] + recc(nums, i, k-1, dp) + recc(nums, k+1, j, dp));
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int c = nums.size();
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return recc(nums, 1, c-2, dp);
    }
    // int recc(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
    //     if(i > j) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int maxi = 0;
    //     for(int ind = i; ind <= j; ind++){
    //         int cost = nums[i-1] * nums[ind] * nums[j+1] + recc(nums, i, ind-1, dp) + recc(nums, ind+1, j, dp);
    //         maxi = max(cost, maxi);
    //     }
    //     return dp[i][j] = maxi;
    // }
    // int maxCoins(vector<int>& nums) {
    //     nums.insert(nums.begin(), 1);
    //     nums.push_back(1);
    //     int c = nums.size();
    //     vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
    //     return recc(nums, 1, c-2, dp);
    // }
    // int maxCoins(vector<int>& nums) {
    //     nums.insert(nums.begin(), 1);
    //     nums.push_back(1);
    //     int c = nums.size();
    //     vector<vector<int>> dp(c+1, vector<int>(c+1, 0));
    //     for(int i=c-2; i>=1; i--){
    //         for(int j=1; j<=c-2; j++){
    //             if(i > j) continue;
    //             int maxi = 0;
    //             for(int ind = i; ind <= j; ind++){
    //                 int cost = nums[i-1] * nums[ind] * nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
    //                 maxi = max(cost, maxi);
    //             }
    //             dp[i][j] = maxi;
    //         }
    //     }
    //     return dp[1][c-2];
    // }
};