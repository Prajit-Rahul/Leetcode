class Solution {
public:
    int recc(vector<int> &cost, int n, vector<int> &dp){
        if(n == 0 || n == 1) return 0;
        if(dp[n] != -1) return dp[n];
        int take1 = recc(cost, n-1, dp) + cost[n-1];
        int take2 = recc(cost, n-2, dp) + cost[n-2];
        return dp[n] = min(take1, take2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return recc(cost, n, dp);
    }
};