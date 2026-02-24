class Solution {
public:
    vector<string> ans;
    void recc(string &s, unordered_set<string> &st, int ind, vector<string> &temp){
        if(ind == s.length()){
            string res = "";
            for(auto &it: temp){
                res += it + " ";
            }
            res.pop_back();
            ans.push_back(res);
            return;
        }
        // if(dp[ind] != -1) return dp[ind];
        for(int i=ind; i<s.length();i++){
            if(st.count(s.substr(ind, i-ind+1)) > 0){
                temp.push_back(s.substr(ind, i-ind+1));
                recc(s, st, i+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st;
        for(auto &it: wordDict){
            st.insert(it);
        }
        vector<string> temp;
        vector<int> dp(s.length(), -1);
        recc(s, st, 0, temp);
        return ans;
    }
};