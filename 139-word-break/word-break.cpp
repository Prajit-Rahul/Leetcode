class Solution {
public:
    bool recc(string &s, unordered_set<string> &st, int ind, vector<int> &dp){
        if(ind == s.length()) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int i=ind; i<s.length();i++){
            if(st.count(s.substr(ind, i-ind+1)) > 0 && recc(s, st, i+1, dp)) 
                return dp[ind] = true; 
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto &it: wordDict){
            st.insert(it);
        }
        vector<int> dp(s.length(), -1);
        return recc(s, st, 0, dp);
    }
};