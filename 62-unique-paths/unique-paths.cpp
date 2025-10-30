class Solution {
public:
    // int recc(int i, int j, vector<vector<int>> &dp){
    //     if(i < 0 || j < 0) return 0;
    //     if(i == 0 && j == 0) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int top = recc(i-1, j, dp);
    //     int bottom = recc(i, j-1, dp);
    //     return dp[i][j] = top + bottom;
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return recc(m-1, n-1, dp);
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, 0));
    //     for(int i=0; i<m; i++){
    //         for(int j=0; j<n; j++){
    //             if(i == 0 && j == 0) dp[i][j] = 1;
    //             else{
    //                 int top = (i-1>=0)?dp[i-1][j]:0;
    //                 int bottom = (j-1>=0)?dp[i][j-1]:0;
    //                 dp[i][j] = top + bottom;
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }
    int uniquePaths(int m, int n) {
        vector<int> curr(n, 0), prev(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int top = (i-1>=0)?prev[j]:0;
                    int bottom = (j-1>=0)?curr[j-1]:0;
                    curr[j] = top + bottom;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};