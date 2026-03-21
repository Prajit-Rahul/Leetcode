class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        for(int i=n-3; i>=0; i--){
            char prev = s[0];
            for(int j=1; j<i+3; j++){
                char ch = s[j];
                s[j-1] = ((s[j] - '0') + (prev - '0'))%10 + '0';
                prev = ch;
            }
        }
        if(s[0] == s[1]) return true;
        return false;
    }
};