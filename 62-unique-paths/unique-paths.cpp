class Solution {
public:
    int recc(int i, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int top = recc(i-1, j, dp);
        int bottom = recc(i, j-1, dp);
        return dp[i][j] = top + bottom;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recc(m-1, n-1, dp);
    }
};