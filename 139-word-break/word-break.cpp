class Solution {
public:
    bool recc(string &s, unordered_set<string>& st, int ind, vector<int> &dp){
        if(ind == s.length()) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int i=ind; i<s.length(); i++){
            string sub = s.substr(ind, i-ind+1);
            if(st.count(sub) > 0 && recc(s, st, i+1, dp)) return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1, -1);
        unordered_set<string> st;
        for(auto &it: wordDict){
            st.insert(it);
        }
        return recc(s, st, 0, dp);
    }
};