class Solution {
public:
    int recc(vector<int>& cost, int ind, vector<int> &dp){
        if(ind <= 1){
            if(ind == 0 || ind == 1)
                return cost[ind];
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int take1 = recc(cost, ind-1, dp);
        int take2 = recc(cost, ind-2, dp);
        if(ind == cost.size()) return min(take1, take2);
        return dp[ind] = min(take1, take2) + cost[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return recc(cost, n, dp);
    }
};