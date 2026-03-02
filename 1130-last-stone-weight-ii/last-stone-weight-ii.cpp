class Solution {
public:
    int recc(vector<int>& stones, int ind, int target, vector<vector<int>> &dp){
        if(ind == stones.size()) return 0;
        if(dp[ind][target] != -1) return dp[ind][target];
        int ntake = recc(stones, ind+1, target, dp);
        int take = 0;
        if(target - stones[ind] >= 0){
            take = stones[ind]+recc(stones, ind+1, target - stones[ind], dp);
        }
        return dp[ind][target] = max(take, ntake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        int n = stones.size();
        for(auto &it: stones){
            total += it;
        }
        int target = total/2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return total - 2*recc(stones, 0, target, dp);
    }
};