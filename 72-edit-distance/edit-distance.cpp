class Solution {
public:
    int edit(string word1, string word2, int ind1, int ind2, vector<vector<long long>> &dp){
        if(ind2 < 0) return ind1+1;
        if(ind1 < 0) return ind2+1;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int change = INT_MAX, nchange = INT_MAX;
        if(word1[ind1] == word2[ind2]){
            nchange = edit(word1, word2, ind1-1, ind2-1, dp);
        }
        else{
        int i = edit(word1, word2, ind1, ind2-1, dp);
        int u = edit(word1, word2, ind1-1, ind2-1, dp);
        int d = edit(word1, word2, ind1-1, ind2, dp);
        change = 1+min({i,u,d});
        }
        return dp[ind1][ind2] = min(change, nchange);
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<long long>> dp(n, vector<long long> (m, -1));
        return edit(word1, word2, n-1, m-1, dp);
    }
    // int recc(string word1, string word2, int ind1, int ind2, vector<vector<int>> &dp){
    //     if(ind1 < 0) return ind2+1;
    //     if(ind2 < 0) return ind1+1;
    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    //     int take = INT_MAX, ntake = INT_MAX;
    //     if(word1[ind1] == word2[ind2]) ntake = recc(word1, word2, ind1-1, ind2-1, dp);
    //     else{
    //         int insert = recc(word1, word2, ind1-1, ind2, dp);
    //         int del = recc(word1, word2, ind1, ind2-1, dp);
    //         int replace = recc(word1, word2, ind1-1, ind2-1, dp);
    //         take = min({insert, del, replace}) + 1;
    //     }
    //     return dp[ind1][ind2] = min(ntake, take);
    // }
    // int minDistance(string word1, string word2) {
    //     int n = word1.size(), m = word2.size();
    //     vector<vector<int>> dp(n, vector<int> (m, -1));
    //     return recc(word1, word2, n-1, m-1, dp);
    // }
    // int minDistance(string word1, string word2) {
    //     int n = word1.size(), m = word2.size();
    //     vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    //     for(int i=1; i<=n; i++){
    //         dp[i][0] = i;
    //     }
    //     for(int i=1; i<=m; i++){
    //         dp[0][i] = i;
    //     }
    //     for(int ind1=1; ind1<=n; ind1++){
    //         for(int ind2=1; ind2<=m; ind2++){
    //             int take = INT_MAX, ntake = INT_MAX;
    //             if(word1[ind1-1] == word2[ind2-1]) ntake = dp[ind1-1][ind2-1];
    //             else{
    //                 int insert = dp[ind1-1][ind2];
    //                 int del = dp[ind1][ind2-1];
    //                 int replace = dp[ind1-1][ind2-1];
    //                 take = min({insert, del, replace}) + 1;
    //             }
    //             dp[ind1][ind2] = min(ntake, take);
    //         }
    //     }
    //     return dp[n][m];
    // }
};