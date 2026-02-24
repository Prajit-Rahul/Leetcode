class Solution {
public:
    unordered_map<int, vector<string>> dp;
    vector<string> recc(string &s, unordered_set<string> &st, int ind){
        if(dp.count(ind)) return dp[ind];
        vector<string> res;
        if(ind == s.length()){
            res.push_back("");
            return dp[ind] = res;
        }
        for(int i=ind; i<s.length(); i++){
            string word = s.substr(ind, i-ind+1);
            if(st.count(word)){
                vector<string> suffix = recc(s, st, i+1);

                for(auto &sentence: suffix){
                    if(sentence == ""){
                        res.push_back(word);
                    }
                    else{
                        res.push_back(word + " " + sentence);
                    }
                }
            }
        }
        return dp[ind] = res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto &it: wordDict){
            st.insert(it);
        }
        return recc(s, st, 0);
    }
};