class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int ind = 0, minLen = INT_MAX;
        for(int i=0; i<strs.size(); i++){
            int len = strs[i].length();
            if(minLen > len)
                minLen = len;
        }
        for(int i=0; i<minLen; i++){
            char ch = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(ch != strs[j][i]){
                    return ans;
                }
            }
            ans += ch;
        }
        return ans;
    }
};