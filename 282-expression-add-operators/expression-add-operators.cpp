class Solution {
public:
    vector<string> ans;
    void recc(string &s, int target, int ind, string temp, long long curr, long long last){
        if(ind == s.length()){
            if(target == curr) ans.push_back(temp);
            return;
        }
        for(int i=ind; i<s.length(); i++){
            string part = s.substr(ind, i-ind+1);
            if(part.length() > 1 && part[0] == '0') break;
            long long num = stoll(part);
            if(ind == 0){
                recc(s, target, i+1, part, num, num);
            }
            else{
                recc(s, target, i+1, temp+"+"+part, curr+num, num);
                recc(s, target, i+1, temp+"-"+part, curr-num, -num);
                recc(s, target, i+1, temp+"*"+part, curr - last + last * num, last*num);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        // string temp;
        recc(num, target, 0, "", 0, 0);
        return ans;
    }
};