class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int sign = 1, i = 0;
        for(;i<s.length(); i++){
            if(s[i] == ' ') continue;
            break;
        }
        if(i<s.length() && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        for(; i<s.length(); i++){
            if(!isdigit(s[i])) break;
            int ch = s[i] - '0';
            if((INT_MAX - ch)/10  < num){
                if(sign == -1) return INT_MIN;
                return INT_MAX;
            }
            num = num * 10 + ch;
        }
        
        return num*sign;
    }
};