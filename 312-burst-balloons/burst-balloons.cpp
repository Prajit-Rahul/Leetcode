class Solution {
public:
    int recc(vector<int>& nums, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 0;
        for(int k=i; k<=j; k++){
            int cost = nums[i-1]*nums[j+1]*nums[k] + recc(nums, i, k-1, dp) + recc(nums, k+1, j, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int c = nums.size();
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return recc(nums, 1, c-2, dp);
    }
};