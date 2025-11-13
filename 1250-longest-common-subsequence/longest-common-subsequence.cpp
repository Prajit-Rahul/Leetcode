class Solution {
public:
    int recc(string &text1, string &text2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1 == text1.length() || ind2 == text2.length()){
            return 0;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int len = 0, ntake1 = 0, ntake2=0; 
        if(text1[ind1] == text2[ind2]){
            len = 1 + recc(text1, text2, ind1+1, ind2+1, dp);
        }
        ntake1 = recc(text1, text2, ind1+1, ind2, dp);
        ntake2 = recc(text1, text2, ind1, ind2+1, dp);
        return dp[ind1][ind2] = max({len, ntake1, ntake2});
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return recc(text1, text2, 0, 0, dp);
    }
};