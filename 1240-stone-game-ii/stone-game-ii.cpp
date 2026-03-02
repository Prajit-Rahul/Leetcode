class Solution {
public:
    int recc(int ind, int m, vector<int>& suffixSum, vector<vector<int>> &dp){
        if(ind == suffixSum.size()) return 0;
        if(ind + 2 * m >= suffixSum.size()) return suffixSum[ind];
        if(dp[ind][m] != -1) return dp[ind][m];
        int res = 0;
        for(int x=1; x<=2*m; x++){
            res = max(res, suffixSum[ind] - recc(ind+x, max(x, m), suffixSum, dp));
        }
        return dp[ind][m] = res;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(piles.empty()) return 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> suffix(n);
        suffix[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i] = piles[i] + suffix[i+1];
        }
        return recc(0, 1, suffix, dp);
    }
};