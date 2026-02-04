class Solution {
public:
    int recc(int m, int n, vector<vector<int>> &dp){
        if(n == 0 && m == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int top = recc(m-1, n, dp);
        int left = recc(m, n-1, dp);
        return dp[m][n] = top + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return recc(m-1, n-1, dp);
    }
};