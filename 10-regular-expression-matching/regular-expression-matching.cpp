class Solution {
public:
    bool recc(string &s, string &p, int ind1, int ind2, vector<vector<int>> &dp){
        int n = s.length(), m = p.length();
        if(ind2 >= m){
            return (ind1 == n);
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        bool select = false, notSelect = false;
        bool match = ind1 < n && (s[ind1] == p[ind2] || p[ind2] == '.');
        if(match)
            select = recc(s, p, ind1+1, ind2+1, dp);
        if((ind2 + 1) < m && p[ind2+1] == '*'){
            notSelect = recc(s, p, ind1, ind2+2, dp) ||
                (match && recc(s, p, ind1+1, ind2, dp));
        }
        return dp[ind1][ind2] = (select || notSelect);
    }
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return recc(s, p, 0, 0, dp);
    }
};