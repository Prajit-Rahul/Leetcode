class Solution {
public:
    int recc(int n, vector<int> &dp){
        if(n <= 0){
            if(n == 0) return 1;
            return 0;
        }
        if(dp[n] != -1) return dp[n];
        int l1 = recc(n-1, dp);
        int l2 = recc(n-2, dp);
        return dp[n] = l1+l2;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return recc(n, dp);
    }
};