class Solution {
public:
    // int recc(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp){
    //     if(ind == 0){
    //         if(amount % coins[ind] == 0) return amount/coins[ind];
    //         return 1e9;
    //     }
    //     if(dp[ind][amount] != -1) return dp[ind][amount];
    //     int ntake = recc(coins, amount, ind-1, dp);
    //     int take = INT_MAX;
    //     if(amount >= coins[ind]) take = 1 + recc(coins, amount-coins[ind], ind, dp);
    //     return dp[ind][amount] = min(take, ntake);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
    //     int ans = recc(coins, amount, n-1, dp);
    //     return ans >= 1e9?-1:ans;
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     const int INF = 1e9;
    //     vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
    //     for(int i=0; i<=amount; i++){
    //         if(i % coins[0] == 0) dp[0][i] = i/coins[0];
    //         else dp[0][i] = INF;
    //     }
    //     for(int ind=1; ind<n; ind++){
    //         for(int amt = 1; amt <= amount; amt++){
    //             int ntake = dp[ind-1][amt];
    //             int take = INF;
    //             if(amt >= coins[ind]) take = 1 + dp[ind][amt-coins[ind]];
    //             dp[ind][amt] = min(take, ntake);
    //         }
    //     }
    //     return dp[n-1][amount] >= INF?-1:dp[n-1][amount];
    // }
    // int recc(vector<int> &coins, int amount, vector<int> &dp){
    //     int len = INT_MAX;
    //     if(amount <= 0) return 0;
    //     if(dp[amount] != -1) return dp[amount];
    //     for(auto &it: coins){
    //         if(amount - it >= 0){
    //             int res = recc(coins, amount-it, dp);
    //             if(res < INT_MAX) len = min(1 + res, len);
    //         } 
    //     }
    //     return dp[amount] = len;
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<int> dp(amount+1, -1);
    //     int ans = recc(coins, amount, dp);
    //     return ans >= INT_MAX?-1:ans;
    // }
    int recc(vector<int> &coins, int amount, vector<int> &dp){
        int len = INT_MAX;
        if(amount <= 0) return 0;
        if(dp[amount] != -1) return dp[amount];
        for(auto &it: coins){
            if(amount - it >= 0){
                int res = recc(coins, amount-it, dp);
                if(res < INT_MAX) len = min(1 + res, len);
            } 
        }
        return dp[amount] = len;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int amt=1; amt<=amount; amt++){
            int len = INT_MAX;
            for(auto &it: coins){
            if(amt - it >= 0){
                int res = dp[amt-it];
                if(res < INT_MAX) len = min(1 + res, len);
            } 
            dp[amt] = len;
        }
        }
        return dp[amount] >= INT_MAX?-1:dp[amount];
    }
};