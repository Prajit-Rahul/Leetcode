class Solution {
public:
    int myAtoi(string s) {
        int i=0, n = s.length(), sign = 1, num = 0;
        while(i<n && (s[i] == ' ')) i++;
        if(i<n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        while(i<n){
            if(!isdigit(s[i])) break;
            int digit = s[i] - '0';
            if((INT_MAX-digit)/10 < num){
                if(sign == -1) return INT_MIN;
                return INT_MAX;
            }
            num = num * 10 + digit;
            i++;
        }
        return num*sign;
    }
};