class Solution {
public:
    // int recc(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int btake = 0;
    //     if(text1[i] == text2[j]) btake = 1 + recc(text1, text2, i-1, j-1, dp);
    //     int take1 = recc(text1, text2, i-1, j, dp);
    //     int take2 = recc(text1, text2, i, j-1, dp);
    //     return dp[i][j] = max({btake, take1, take2});
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.size(), m = text2.size();
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     return recc(text1, text2, n-1, m-1, dp);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int btake = 0;
                if(text1[i] == text2[j]) btake = 1 + dp[i][j];
                int take1 = dp[i][j+1];
                int take2 = dp[i+1][j];
                dp[i+1][j+1] = max({btake, take1, take2});
            }
        }
        return dp[n][m];
    }
};