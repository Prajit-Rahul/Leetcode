class Solution {
public:
    bool isPal(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    void recc(string &s, int ind, vector<vector<string>> &ans, vector<string> &temp){
        if(ind == s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<s.length(); i++){
            if(isPal(s,ind,i)){
                temp.push_back(s.substr(ind, i-ind+1));
                recc(s, i+1, ans, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        recc(s, 0, ans, temp);
        return ans;
    }
};