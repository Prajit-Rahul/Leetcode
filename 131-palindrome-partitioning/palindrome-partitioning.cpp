class Solution {
public:
    vector<vector<string>> ans;
    bool isPal(string &str, int ind, int i){
        while(ind < i){
            if(str[ind] != str[i]){
                return false;
            }
            ind++;
            i--;
        }
        return true;
    }
    void recc(string s, vector<string> &temp, int ind){
        if(s.length() == ind){
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<s.length(); i++){
            if(isPal(s, ind, i)){
                temp.push_back(s.substr(ind, i-ind+1));
                recc(s, temp, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        recc(s, temp, 0);
        return ans;
    }
};