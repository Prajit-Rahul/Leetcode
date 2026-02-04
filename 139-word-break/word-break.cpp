class Solution {
public:
    bool recc(string &s, vector<string>& wordDict, int ind, vector<int> &dp){
        if(ind == s.length()) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int i=ind; i<s.length(); i++){
            for(auto &it: wordDict){
                if(s.substr(ind, i-ind+1) == it && recc(s, wordDict, i+1, dp)) return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1, -1);
        return recc(s, wordDict, 0, dp);
    }
};