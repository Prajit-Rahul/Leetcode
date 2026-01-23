class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r = 1, n = prices.size();
        int ans = 0;
        while(r<n){
            if(prices[l] < prices[r]){
                ans = max(prices[r] - prices[l], ans);
            }
            else {
                l = r;
            }
            r++;
        }
        return ans;
    }
};