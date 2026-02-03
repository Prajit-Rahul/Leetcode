class Solution {
public:
    int countSubstrings(string s) {
        int count = 0; 
        int n = s.length();
        for(int i=0; i<n; i++){
            int r = i, l = i;
            while(l>=0 && r<n && s[l] == s[r]){
                l--, r++;
                count++;
            }
            r = i+1, l = i;
            while(l>=0 && r<n && s[l] == s[r]){
                l--, r++;
                count++;
            }
        }
        return count;
    }

};