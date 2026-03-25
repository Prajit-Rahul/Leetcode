class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> preSum(n, vector<long long>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                preSum[i][j] += grid[i][j];
                if(i>0) preSum[i][j] += preSum[i-1][j];
                if(j>0) preSum[i][j] += preSum[i][j-1];
                if(i>0 && j>0) preSum[i][j] -= preSum[i-1][j-1];
            }
        }
        for(int i=0; i<n-1; i++){
            if(preSum[i][m-1] * 2 == preSum[n-1][m-1]) return true;
        }
        for(int j=0; j<m-1; j++){
            if(preSum[n-1][j] * 2 == preSum[n-1][m-1]) return true;
        }
        return false;
    }
};