class Solution {
public:
    // int recc(string &s, string &t, int ind1, int ind2, vector<vector<int>> &dp){
    //     if(ind2 < 0) return 1;
    //     if(ind1 < 0) return 0;
    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    //     int take = 0;
    //     if(s[ind1] == t[ind2]) take += recc(s, t, ind1-1, ind2-1, dp);
    //     int ntake = recc(s, t, ind1-1, ind2, dp);
    //     return dp[ind1][ind2] = take + ntake;
    // }
    // int numDistinct(string s, string t) {
    //     int n = s.length(), m = t.length();
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     return recc(s, t, n-1, m-1, dp);
    // }
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<unsigned>> dp(n+1, vector<unsigned>(m+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=1; ind2<=m; ind2++){
                if(s[ind1-1] == t[ind2-1]) dp[ind1][ind2] += dp[ind1-1][ind2-1];
                dp[ind1][ind2] += dp[ind1-1][ind2];
            }
        }
        return dp[n][m];
    }
};