class Solution {
public:
    // int recc(vector<int>& prices, int ind, int buy, vector<vector<int>> &dp){
    //     if(ind >= prices.size()) return 0;
    //     if(dp[ind][buy] != -1) return dp[ind][buy];
    //     int b = 0;
    //     if(buy == 1) b = recc(prices, ind+1, 0, dp) - prices[ind];
    //     int s = 0;
    //     if(buy == 0) s = recc(prices, ind+2, 1, dp) + prices[ind];
    //     int n = recc(prices, ind+1, buy, dp);
    //     return dp[ind][buy] = max({b, s, n});
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, -1));
    //     return recc(prices, 0, 1, dp); 
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next_next(2, 0), next(2, 0), curr(2, 0);
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<2; buy++){
                int b = 0;
                if(buy == 1) b = next[0] - prices[ind];
                int s = 0;
                if(buy == 0) s = next_next[1] + prices[ind];
                int n1 = next[buy];
                curr[buy] = max({b, s, n1});
            }
            next_next = next;
            next = curr;
        }
        return next[1]; 
    }
};