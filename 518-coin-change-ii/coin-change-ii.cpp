class Solution {
public:
    // int recc(int amount, vector<int>& coins, int ind, vector<vector<int>> &dp){
    //     if(amount == 0 && ind == 0) return 1;
    //     if(amount < 0 || ind < 0){ 
    //         return 0;
    //     }
    //     if(dp[ind][amount] != -1) return dp[ind][amount];
    //     int take = recc(amount-coins[ind], coins, ind, dp);
    //     int ntake = recc(amount, coins, ind-1, dp);
    //     return dp[ind][amount] = take + ntake;
    // }
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    //     return recc(amount, coins, n-1, dp);
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned>> dp(n+1, vector<unsigned>(amount+1, 0));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = 1;
        // }
        for(int ind=0; ind<=n-1; ind++){
            for(int amt=0; amt<=amount; amt++){
                if(ind == 0 && amt%coins[0] == 0) dp[ind][amt] = 1;
                else{
                    if(amt >= coins[ind]) dp[ind][amt] = dp[ind][amt-coins[ind]];
                    if(ind > 0) dp[ind][amt] += dp[ind-1][amt];
                }
            }
        }
        return dp[n-1][amount];
    }
};