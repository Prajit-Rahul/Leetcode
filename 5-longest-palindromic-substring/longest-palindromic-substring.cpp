class Solution {
public:
    
    string longestPalindrome(string s) {
        string res = "";
        int n = s.length();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int l = i, r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxLen < r-l+1){
                    maxLen = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--, r++;
            }
            l = i, r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxLen < r-l+1){
                    maxLen = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--, r++;
            }
        }
        return res;
    }
};