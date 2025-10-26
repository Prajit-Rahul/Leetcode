class Solution {
public:
    int recc(vector<int> &cost, int i, vector<int> &dp){
        if(i >= cost.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int left = recc(cost, i+1, dp) + cost[i];
        int right = recc(cost, i+2, dp) + cost[i];
        return dp[i] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return min(recc(cost, 0, dp), recc(cost, 1, dp));
    }
};