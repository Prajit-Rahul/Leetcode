class Solution {
public:
    int recc(vector<int>& prices, int ind, int buy, vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int b = 0;
        if(buy == 1) b = recc(prices, ind+1, 0, dp) - prices[ind];
        int s = 0;
        if(buy == 0) s = recc(prices, ind+2, 1, dp) + prices[ind];
        int n = recc(prices, ind+1, buy, dp);
        return dp[ind][buy] = max({b, s, n});
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return recc(prices, 0, 1, dp); 
    }
};