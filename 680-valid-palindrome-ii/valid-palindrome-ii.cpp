class Solution {
public:
    bool isPal(string &s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        bool flag = false;
        int i=0, j=s.length()-1;
        while(i<=j){
            if(s[i] == s[j]){
                i++, j--;
            }
            else if(s[i+1] == s[j] || s[i] == s[j-1]){
                return isPal(s, i+1, j) || isPal(s, i, j-1);
            }
            else{
                return false;
            }
        }
        return true;
    }
};