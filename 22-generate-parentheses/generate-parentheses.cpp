class Solution {
public:
    void recc(string s, vector<string> &ans, int open, int close){
        if(close == 0 && open == 0){
            ans.push_back(s);
            return;
        }
        if(open != 0){
            s.append("(");
            recc(s, ans, open-1, close);
            s.pop_back();
        }
        if(close > open){
            s.append(")");
            recc(s, ans, open, close-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        recc(s, ans, n, n);
        return ans;
    }
};