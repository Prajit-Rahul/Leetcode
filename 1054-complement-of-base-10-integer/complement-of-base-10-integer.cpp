class Solution {
public:
    int bitwiseComplement(int n) {
        int temp = n, mask = 0;
        if(n == 0) return 1;
        while(temp){
            mask = (mask<<1) | 1;
            temp>>=1;
        }
        return n^mask;
    }
};