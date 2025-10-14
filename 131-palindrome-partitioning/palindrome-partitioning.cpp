class Solution {
public:
    vector<vector<string>> ans;
    void recc(string s, int ind, vector<string> &temp){
        if(s.length() <= ind){
            if(s.length() == ind) ans.push_back(temp);
            return;
        }
        for(int i=ind; i<s.length(); i++){
            if(isPalindrome(s, ind, i)){
                temp.push_back(s.substr(ind, i - ind + 1));
                recc(s, i+1, temp);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        recc(s, 0, temp);
        return ans;
    }
};