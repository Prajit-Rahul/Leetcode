class Solution {
public:
    const int mod = 1e9 + 7; 
    int solve(int ind, int n, int prev1, int prev2, int prev3, vector<vector<vector<vector<int>>>> &dp){
        if(ind == n) return 1;
        if(dp[ind][prev1+1][prev2+1][prev3+1] != -1) return dp[ind][prev1+1][prev2+1][prev3+1];
        int ans = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    if(i != j && j != k && i != prev1 && j != prev2 && k != prev3){
                        ans = (ans + solve(ind+1, n, i, j, k, dp))%mod;
                    }
                }
            }
        }
        return dp[ind][prev1+1][prev2+1][prev3+1] = ans;
    }
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, -1))));
        return solve(0, n, -1, -1, -1, dp);
    }
};