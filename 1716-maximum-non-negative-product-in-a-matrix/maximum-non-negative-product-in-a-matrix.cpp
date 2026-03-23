class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dpMin(n, vector<long long>(m, -1)), dpMax(n, vector<long long>(m));
        dpMin[0][0] = dpMax[0][0] = grid[0][0];
        for(int i=1; i<n; i++){
            dpMin[i][0] = dpMax[i][0] = grid[i][0] * dpMax[i-1][0];
        }
        for(int j=1; j<m; j++){
            dpMin[0][j] = dpMax[0][j] = grid[0][j] * dpMax[0][j-1];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                long long a = grid[i][j] * dpMin[i-1][j];
                long long b = grid[i][j] * dpMax[i-1][j];
                long long c = grid[i][j] * dpMin[i][j-1];
                long long d = grid[i][j] * dpMax[i][j-1];
                dpMin[i][j] = min({a, b, c, d});
                dpMax[i][j] = max({a, b, c, d});
            }
        }
        long long ans = dpMax[n-1][m-1];
        if(ans < 0) return -1;
        return ans%MOD;
    }
};