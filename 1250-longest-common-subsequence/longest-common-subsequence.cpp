class Solution {
public:
    int recc(string &text1, string &text2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int btake = 0;
        if(text1[ind1] == text2[ind2]) btake = 1 + recc(text1, text2, ind1-1, ind2-1, dp);
        int ntake1 = recc(text1, text2, ind1-1, ind2, dp);
        int ntake2 = recc(text1, text2, ind1, ind2-1, dp);
        return dp[ind1][ind2] = max({btake, ntake1, ntake2});
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return recc(text1, text2, n-1, m-1, dp);
    }
};