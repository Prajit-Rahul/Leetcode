class Solution {
public:
    int recc(vector<int>& piles, int ind, int n, vector<vector<int>> &dp){
        if(ind > n) return 0;
        if(dp[ind][n] != -1) return dp[ind][n];
        int take1 = piles[ind] - recc(piles, ind+1, n, dp);
        int take2 = piles[n] - recc(piles, ind, n-1, dp);
        return dp[ind][n] = max(take1, take2);
    }
    bool stoneGame(vector<int>& piles) {
        int sum = 0, n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recc(piles, 0, n-1, dp);
    }
};