class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0, n = s.length();
        int maxi = 0;
        string res = "";
        for(int i=0; i < n; i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(maxi < r-l+1){
                    maxi = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--, r++;
            }
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(maxi < r-l+1){
                    maxi = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--, r++;
            }
        }
        return res;
    }
};