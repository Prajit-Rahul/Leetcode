class Solution {
public:
    int recc(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        int n = grid.size(), m = grid[0].size();
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }
        if(i >= n || j >= m || i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int b = recc(grid, i+1, j, dp);
        int r = recc(grid, i, j+1, dp);
        return dp[i][j] = min(b,r) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return recc(grid, 0, 0, dp);
    }
};