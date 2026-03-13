class Solution {
public:
    int recc(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j] <= prev) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans = max(ans, 1+recc(matrix, i+1, j, matrix[i][j], dp));
        ans = max(ans, 1+recc(matrix, i, j+1, matrix[i][j], dp));
        ans = max(ans, 1+recc(matrix, i, j-1, matrix[i][j], dp));
        ans = max(ans, 1+recc(matrix, i-1, j, matrix[i][j], dp));
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxi = max(maxi, recc(matrix, i, j, -1, dp));
            }
        }
        return maxi;
    }
    // int recc(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<int>> &dp){
    //     int ans = 0;
    //     if(i >= matrix.size() || j >= matrix[0].size() || i < 0 || j < 0 || matrix[i][j] <= prev) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     ans = max(ans,1+ recc(matrix, i+1, j, matrix[i][j], dp));
    //     ans = max(ans,1+ recc(matrix, i, j+1, matrix[i][j], dp));
    //     ans = max(ans,1+ recc(matrix, i, j-1, matrix[i][j], dp));
    //     ans = max(ans,1+ recc(matrix, i-1, j, matrix[i][j], dp));
    //     return dp[i][j] = ans;
    // }

    // int longestIncreasingPath(vector<vector<int>>& matrix) {
    //     int n = matrix.size(), m = matrix[0].size();
    //     int maxi = 0;
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<m; j++){
    //             maxi = max(maxi, recc(matrix, i, j, -1, dp));
    //         }
    //     }
    //     return maxi;
    // }
};