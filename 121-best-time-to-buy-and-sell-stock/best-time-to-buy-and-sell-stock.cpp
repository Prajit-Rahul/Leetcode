class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, l = 0, r=1, maxProfit = 0;
        while(r<prices.size()){
            profit = prices[r] - prices[l];
            if(prices[r] - prices[l] < 0){
                l = r;
            }
            else{
                maxProfit = max(maxProfit, profit);
            }
            r++;
        }
        return maxProfit;
    }
};