class Solution {
public:
    int numSub(string s) {
        long long count = 0;
        const int MOD = 1e9 + 7;
        long long sum = 0;
        int n = s.length();
        for(auto &it: s){
            if(it == '0'){
                sum = (sum + (count*(count+1))/2)%MOD ;
                count = 0;
            }
            else{
                count++;
            }
        }
        if(s[n-1] != '0') sum += (count*(count+1))/2;
        return sum;
    }
};