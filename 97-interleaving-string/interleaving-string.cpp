class Solution {
public:
    bool recc(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp){
        if(i == s1.length() && j == s2.length()){
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool take1 = false, take2 = false;
        if(s1[i] == s3[i+j])
            take1 = recc(s1, s2, s3, i+1, j, dp);
        if(s2[j] == s3[i+j])
            take2 = recc(s1, s2, s3, i, j+1, dp);
        return dp[i][j] = take1 || take2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), l = s3.length();
        if(l == 0) return true;
        if(n + m != l) return false;
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return recc(s1, s2, s3, 0, 0, dp);
    }
    // bool recc(string &s1, string &s2, string &s3, int ind1, int ind2, vector<vector<int>> &dp){
    //     bool ans = false;
    //     if(ind1 + ind2 >= s3.length()){
    //         if(ind1 == s1.length() && ind2 == s2.length()) return true;
    //         return false;
    //     }
    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    //     if(ind1 < s1.length() && s1[ind1] == s3[ind1+ind2]) ans = ans || recc(s1, s2, s3, ind1+1, ind2, dp);
    //     if(ind2 < s2.length() && s2[ind2] == s3[ind1+ind2]) ans = ans || recc(s1, s2, s3, ind1, ind2+1, dp);
    //     return dp[ind1][ind2] = ans;
    // }
    // bool isInterleave(string s1, string s2, string s3) {
    //     int n = s1.length(), m = s2.length(), l = s3.length();
    //     if(l == 0) return true;
    //     if(n + m != l) return false;
    //     vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    //     return recc(s1, s2, s3, 0, 0, dp);
    // }
};