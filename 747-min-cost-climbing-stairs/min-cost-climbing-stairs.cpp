class Solution {
public:
    int recc(vector<int> &cost, int i, vector<int> &dp){
        if(i < 0) return 0;
        if(i == 0 || i == 1) return cost[i];
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(recc(cost, i-1, dp), recc(cost, i-2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(recc(cost, n-1, dp), recc(cost, n-2, dp));
    }
};