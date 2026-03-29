class Solution {
public:
    int recc(vector<int>& prices, int ind, int buy, vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int b = 0, s = 0;
        if(buy){
            b = recc(prices, ind+1, 0, dp) - prices[ind];
        }
        else{
            s = prices[ind] + recc(prices, ind+2, 1, dp);
        }
        int n = recc(prices, ind+1, buy, dp);
        return dp[ind][buy] = max({n, s, b});
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return recc(prices, 0, 1, dp);
    }
};