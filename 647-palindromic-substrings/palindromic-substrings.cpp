class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;
        for(int i=0; i<n; i++){
            int r = i, l = i;
            while(l>=0 && r<n && s[l] == s[r]){
                l--, r++;
                res++;
            }
            r = i+1, l = i;
            while(l>=0 && r<n && s[l] == s[r]){
                l--, r++;
                res++;
            }
        }
        return res;
    }
};