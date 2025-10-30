class Solution {
public:
    int recc(int amount, vector<int>& coins, int ind, vector<vector<int>> &dp){
        if(amount == 0 && ind == 0) return 1;
        if(amount < 0 || ind < 0){ 
            return 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int take = recc(amount-coins[ind], coins, ind, dp);
        int ntake = recc(amount, coins, ind-1, dp);
        return dp[ind][amount] = take + ntake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return recc(amount, coins, n-1, dp);
    }
};