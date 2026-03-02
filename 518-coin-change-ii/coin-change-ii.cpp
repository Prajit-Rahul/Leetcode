class Solution {
public:
    int recc(int amount, vector<int>& coins, int ind, vector<vector<int>> &dp){
        if(ind < 0){
            if(amount == 0) return 1;
            return 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int take = 0;
        if(amount - coins[ind] >= 0)
            take = recc(amount - coins[ind], coins, ind, dp);
        int ntake = recc(amount, coins, ind-1, dp);
        return dp[ind][amount] = take+ntake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return recc(amount, coins, n-1, dp);
    }
    // int recc(int amount, vector<int>& coins, int ind, vector<vector<int>> &dp){
    //     if(ind < 0){
    //         if(amount == 0) return 1;
    //         return 0;
    //     }
    //     if(dp[ind][amount] != -1) return dp[ind][amount];
    //     int take = 0;
    //     if(coins[ind]<=amount)
    //         take = recc(amount-coins[ind], coins, ind, dp);
    //     int ntake = recc(amount, coins, ind-1, dp);
    //     return dp[ind][amount] = take + ntake;
    // }
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
    //     return recc(amount, coins, n-1, dp);
    // }
    // int recc(int amount, vector<int>& coins, int ind, vector<vector<int>> &dp){
    //     if(ind < 0){
    //         if(amount == 0) return 1;
    //         return 0;
    //     }
    //     if(dp[ind][amount] != -1) return dp[ind][amount];
    //     int take = 0;
    //     if(coins[ind]<=amount)
    //         take = recc(amount-coins[ind], coins, ind, dp);
    //     int ntake = recc(amount, coins, ind-1, dp);
    //     return dp[ind][amount] = take + ntake;
    // }
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<unsigned>> dp(n+2, vector<unsigned>(amount+1, 0));
    //     for(int ind=0; ind<n; ind++){
    //         for(int amt=0; amt<=amount; amt++){
    //             if(ind == 0 && amt == 0) dp[ind][amt] = 1;
    //             else{
    //                 if(coins[ind]<=amt)
    //                     dp[ind][amt] += dp[ind][amt-coins[ind]];
    //                 if(ind>0) dp[ind][amt] += dp[ind-1][amt];
    //             }
    //         }
    //     }
    //     return dp[n-1][amount];
    // }
};