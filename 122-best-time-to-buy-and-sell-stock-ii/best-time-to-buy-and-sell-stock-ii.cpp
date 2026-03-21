class Solution {
public:
    int recc(vector<int>& prices, int ind, int buy, vector<vector<int>> &dp){
        if(ind == prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int ans = 0;
        if(buy){
            ans = max(ans, recc(prices, ind+1, 0, dp)-prices[ind]);
        }
        else{
            ans = max(ans, recc(prices, ind+1, 1, dp)+prices[ind]);
        }
        ans = max(ans,recc(prices, ind+1, buy, dp));
        return dp[ind][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return recc(prices, 0, 1, dp);
    }
};