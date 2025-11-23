class Solution {
public:
    int div = 1e9 + 7;
    long long pow(long long x, long long n){
        if(n == 0) return 1;
        long long ans = pow(x, n/2) % div;
        long long sq = (ans * ans)% div;
        if(n % 2 == 0) return sq;
        return (x*sq)%div;

    }
    int countGoodNumbers(long long n) {
        if(n == 1) return 5;
        long long ans = pow(5, n/2) % div;
        ans = (ans * (pow(4, n/2) % div))%div;
        if(n%2 == 1)
            ans = (ans * 5)%div;
        return ans;
    }

};