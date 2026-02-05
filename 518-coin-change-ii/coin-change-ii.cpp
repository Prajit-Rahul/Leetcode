class Solution {
public:
    int recc(int amount, vector<int>& coins, int ind, vector<vector<int>> &dp){
        if(ind < 0){
            if(amount == 0) return 1;
            return 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int take = 0;
        if(coins[ind]<=amount)
            take = recc(amount-coins[ind], coins, ind, dp);
        int ntake = recc(amount, coins, ind-1, dp);
        return dp[ind][amount] = take + ntake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return recc(amount, coins, n-1, dp);
    }
};