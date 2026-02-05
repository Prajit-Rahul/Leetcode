class Solution {
public:
    // int recc(vector<int>& prices, int ind, bool s, vector<vector<int>> &dp){
    //     int buy = 0, sell = 0;
    //     if(ind >= prices.size()) return 0;
    //     if(dp[ind][s] != -1) return dp[ind][s];
    //     if(s){
    //         sell = recc(prices, ind+2, 0, dp) + prices[ind];
    //     }
    //     if(!s) buy = recc(prices, ind+1, 1, dp) - prices[ind];
    //     int n = recc(prices, ind+1, s, dp);
    //     return dp[ind][s] = max({n, sell, buy});
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int> (2, -1));
    //     return recc(prices, 0, 0, dp);
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));
        for(int ind=n-1; ind>=0; ind--){
            
            dp[ind][1] = max(dp[ind+2][0] + prices[ind], dp[ind+1][1]);
            dp[ind][0] = max(dp[ind+1][1] - prices[ind], dp[ind+1][0]);
            
        }
        return dp[0][0];
    }
};