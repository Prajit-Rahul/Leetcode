class Solution {
public:
    double power(double x, long long n){
        if(n == 1) return x;
        if(n == 0) return 1.0;
        double ans = power(x*x, n/2);
        if(n % 2 == 1) return x*ans;
        else return ans;
    }
    double myPow(double x, int n) {
        long long p = abs((long long)n);
        double ans = power(x, p);
        if(n < 0) return 1/ans;
        else if(n == 0) return 1;
        else return ans;
    }
};