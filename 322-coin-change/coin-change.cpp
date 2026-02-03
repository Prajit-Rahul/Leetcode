class Solution {
public: 

    int recc(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp){
        if(ind == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int ntake = recc(coins, amount, ind-1, dp);
        int take = INT_MAX;
        if(coins[ind] <= amount) take = 1 + recc(coins,  amount - coins[ind], ind, dp);
        dp[ind][amount] = min(take, ntake);
        return dp[ind][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = recc(coins, amount, n-1, dp);
        return ans == 1e9?-1:ans;
    }
};