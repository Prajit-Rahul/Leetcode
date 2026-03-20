class Solution {
public:
    vector<vector<int>> freqCount(vector<vector<int>> &grid){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j]+=grid[i][j];
                if(i>0) matrix[i][j] += matrix[i-1][j];
                if(j>0) matrix[i][j] += matrix[i][j-1];
                if(i>0 && j>0) matrix[i][j] -= matrix[i-1][j-1];
            }
        }
        return matrix;
    }
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>> preSum = freqCount(grid);
        int n = grid.size(), m = grid[0].size(), count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(preSum[i][j] <= k) count++;
            }
        }
        return count;
    }
};