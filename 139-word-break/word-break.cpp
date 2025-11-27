class Solution {
public:
    bool recc(const string &s, unordered_set<string> &st, int ind, vector<int> &dp){
        if(ind == s.length()){
            return true;
        }
        if(dp[ind] != -1) return dp[ind];
        for(int i=ind; i<s.length(); i++){
            string sub = s.substr(ind, i-ind+1);
            if(st.count(sub) > 0)
                if(recc(s, st, i+1, dp)) return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int n = s.length();
        vector<int> dp(n, -1);
        for(auto &it: wordDict){
            st.insert(it);
        }
        return recc(s, st, 0, dp);
    }
};