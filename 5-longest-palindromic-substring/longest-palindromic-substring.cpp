class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0, n = s.length();
        int maxi = 0, start = 0;
        for(int i=0; i < n; i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(maxi < r-l+1){
                    start = l;
                    maxi = r-l+1;
                }
                l--, r++;
            }
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(maxi < r-l+1){
                    maxi = r-l+1;
                    start = l;
                }
                l--, r++;
            }
        }
        return s.substr(start, maxi);
    }
};