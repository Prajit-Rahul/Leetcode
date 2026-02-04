class Solution {
public:
    // int recc(int m, int n, vector<vector<int>> &dp){
    //     if(n == 0 && m == 0) return 1;
    //     if(m < 0 || n < 0) return 0;
    //     if(dp[m][n] != -1) return dp[m][n];
    //     int top = recc(m-1, n, dp);
    //     int left = recc(m, n-1, dp);
    //     return dp[m][n] = top + left;
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n,-1));
    //     return recc(m-1, n-1, dp);
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int top = i-1 >= 0 ? dp[i-1][j] : 0;
                    int left = j-1 >= 0 ? dp[i][j-1] : 0;
                    dp[i][j] = top + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};