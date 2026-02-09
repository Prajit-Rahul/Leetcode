class Solution {
public:
    // int hammingWeight(int n) {
    //     int count = 0;
    //     while(n){
    //         count += n & 1;
    //         n >>= 1;
    //     }
    //     return count;
    // }
    int hammingWeight(int n) {
        int count = 0;
        while(n){
            count += n % 2;
            n >>= 1;
        }
        return count;
    }
};