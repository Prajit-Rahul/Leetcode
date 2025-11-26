class Solution {
public:
    vector<string> ans;
    void recc(string digits, int ind, unordered_map<char, string> &mp, string &s){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }
        for(auto &it: mp[digits[ind]]){
            s.push_back(it);
            recc(digits, ind+1, mp, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        string s = "";
        recc(digits, 0, mp, s);
        return ans;
    }
};