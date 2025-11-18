class Solution {
public:
    int mini = INT_MAX;
    int recc(vector<int>& coins, int amount, int ind, vector<vector<int>> &dp){
        if(ind == 0){
            if(amount % coins[ind] == 0) return amount/coins[ind];
            return 1e9;
        }
        if(dp[amount][ind] != -1) return dp[amount][ind];
        int take = (amount - coins[ind]>=0)? 1 + recc(coins, amount - coins[ind], ind, dp):INT_MAX;
        int ntake = recc(coins, amount, ind-1, dp);
        dp[amount][ind] = min(take, ntake);
        mini = min(mini, dp[amount][ind]);
        return dp[amount][ind];
    }
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n,-1));
        int ans = recc(coins, amount, n-1, dp);
        return (ans == INF)?-1:ans;
    }
};