class Solution {
public:
    int mod = 1e9+7;
    int pow(int n){
        if(n == 0){
            return 1;
        }
        int half = pow(n/2);
        if(n%2==0){
            return (half*half)%mod;
        }
        else{
            return ((half*half)%mod*2)%mod;
        }
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        int i = 0;
        while(n>0){
            if(n%2 == 1) power.push_back(pow(i));
            n = n>>1;
            i++;
        }
        vector<int> ans;
        for(auto &it: queries){
            long long prod = 1;
            for(int i=it[0]; i<=it[1]; i++){
                prod = (1ll*prod*power[i])%mod;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};