class Solution {
public:
    bool recc(string &s1, string &s2, string &s3, int i, int j,vector<vector<int>> &dp){
        if(i + j == s3.length()-1){
            if(s3[i+j] == s1[i] || s3[i+j] == s2[j]) return true;
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool t1=false, t2=false;
        if(i<s1.length() && s1[i] == s3[i+j]) t1 = recc(s1, s2, s3, i+1, j, dp);
        if(j<s2.length() && s2[j] == s3[i+j]) t2 = recc(s1, s2, s3, i, j+1, dp); 
        return dp[i][j] = t1 || t2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();
        if(l == 0) return true;
        if(n + m != l) return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return recc(s1, s2, s3, 0, 0, dp);
    }
};