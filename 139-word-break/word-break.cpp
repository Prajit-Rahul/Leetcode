class Solution {
public:
    bool recc(string s, unordered_set<string> &st, int ind, vector<int> &dp){
        if(ind == s.length()) return dp[ind] = true;
        if(dp[ind] != -1) return dp[ind];
        for(int i=ind; i<s.length(); i++){
            string word = s.substr(ind, i-ind+1);
            if(st.find(word) != st.end() && recc(s, st, i+1, dp)){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> dp(s.length()+1, -1);
        for(auto &it: wordDict){
            st.insert(it);
        }
        recc(s, st, 0, dp);
        return dp[0];
    }
};