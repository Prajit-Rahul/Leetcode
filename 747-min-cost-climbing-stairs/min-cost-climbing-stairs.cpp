class Solution {
public:
    int recc(vector<int>& cost, int ind, vector<int> &dp){
        if(ind == 1 || ind == 0) return cost[ind];   
        if(dp[ind] != -1) return dp[ind]; 
        int oneTake = recc(cost, ind-1, dp);
        int twoTake = recc(cost, ind-2, dp);
        if(ind == cost.size()) return min(oneTake, twoTake);
        return dp[ind] = min(oneTake, twoTake) + cost[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return recc(cost, cost.size(), dp);
    }
};