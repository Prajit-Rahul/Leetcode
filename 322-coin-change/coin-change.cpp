class Solution {
public: 

    // int recc(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp){
    //     if(ind == 0){
    //         if(amount % coins[0] == 0) return amount/coins[0];
    //         return 1e9;
    //     }
    //     if(dp[ind][amount] != -1) return dp[ind][amount];
    //     int ntake = recc(coins, amount, ind-1, dp);
    //     int take = INT_MAX;
    //     if(coins[ind] <= amount) take = 1 + recc(coins,  amount - coins[ind], ind, dp);
    //     dp[ind][amount] = min(take, ntake);
    //     return dp[ind][amount];
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
    //     int ans = recc(coins, amount, n-1, dp);
    //     return ans == 1e9?-1:ans;
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
    //         for(int amt=1; amt<=amount; amt++){
    //             int ntake = dp[ind-1][amt];
    //             int take = INF;
    //             if(coins[ind] <= amt) take = 1 + dp[ind][amt - coins[ind]];
    //             dp[ind][amt] = min(take, ntake);
    //         }
    //     }
    //     return dp[n-1][amount] >= 1e9?-1:dp[n-1][amount];
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0) curr[i] = i/coins[0];
            else curr[i] = INF;
        }
        for(int ind=1; ind<n; ind++){
            curr[0] = 0;
            for(int amt=1; amt<=amount; amt++){
                int ntake = curr[amt];
                int take = INF;
                if(coins[ind] <= amt) take = 1 + curr[amt - coins[ind]];
                curr[amt] = min(take, ntake);
            }
            // prev = curr;
        }
        return curr[amount] >= 1e9?-1:curr[amount];
    }
};