class Solution {
public:
    vector<vector<string>> ans;
    void recc(string &s, vector<string> &temp, int ind){
        if(ind >= s.length()){
            if(ind == s.length()) ans.push_back(temp);
            return;
        }
        for(int i=ind; i<s.length(); i++){
            if(isPalindrome(s, ind, i)){
                temp.push_back(s.substr(ind, i - ind + 1));
                recc(s, temp, i+1);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string &s, int ind, int i){
        while(ind < i){
            if(s[ind] != s[i]) return false;
            ind++;
            i--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        recc(s, temp, 0);
        return ans;
    }
};