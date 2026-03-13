class Solution {
public:

    long long minEnd(int n, int x) {
        vector<int> zeros;
        long long ans = x;
        long long bits = n-1;
        for(int i=0; i<32; i++){
            if(!((1<<i) & x)) zeros.push_back(i);
        }
        for(int i=32; i<64; i++){
            zeros.push_back(i);
        }
        for(int i=0; bits>0; i++, bits>>=1){
            ans += (bits & 1) << zeros[i]; 
        }
        return ans;
    }
};