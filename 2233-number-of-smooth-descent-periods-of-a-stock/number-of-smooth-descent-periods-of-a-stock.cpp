class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 1, ans = 1;
        for(int i=0; i<prices.size()-1; i++){
            if(prices[i+1]+1 == prices[i]) count++;
            else count = 1;
            ans += count;
        }
        return ans;
    }
};