class Solution {
public:
    vector<vector<int>> freqCount(vector<vector<char>> &grid, char ch){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == ch) matrix[i][j]++;
                if(i>0) matrix[i][j] += matrix[i-1][j];
                if(j>0) matrix[i][j] += matrix[i][j-1];
                if(i>0 && j>0) matrix[i][j] -= matrix[i-1][j-1];
            }
        }
        return matrix;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>> x_count = freqCount(grid, 'X');
        vector<vector<int>> y_count = freqCount(grid, 'Y');
        int n = grid.size(), m = grid[0].size(), count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(x_count[i][j] == y_count[i][j] && y_count[i][j] != 0) count++;
            }
        }
        return count;
    }
};