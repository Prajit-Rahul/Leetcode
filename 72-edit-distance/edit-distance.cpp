class Solution {
public:
    int recc(string &word1, string &word2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind2 < 0) return ind1+1;
        if(ind1 < 0) return ind2+1; 
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int noOp = INT_MAX, Op = INT_MAX;
        if(word1[ind1] == word2[ind2]) noOp = recc(word1, word2, ind1-1, ind2-1, dp);
        else{
        int insert = 1 + recc(word1, word2, ind1, ind2-1, dp);
        int del = 1 + recc(word1, word2, ind1-1, ind2, dp);
        int update = 1 + recc(word1, word2, ind1-1, ind2-1, dp);
        Op = min({insert, del, update});
        }
        return dp[ind1][ind2] = min(noOp, Op);
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return recc(word1, word2, n-1, m-1, dp);
    }
};