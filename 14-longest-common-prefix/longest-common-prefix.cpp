class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string common = strs[0];
        for(int i=1; i<n; i++){
            int s1 = common.size(), s2 = strs[i].size(), j = 0;
            int m = min(s1, s2);
            while(common[j] == strs[i][j]){
                j++;
                if(j == m) break; 
            }
            common = common.substr(0, j);
        }
        return common;
    }
};