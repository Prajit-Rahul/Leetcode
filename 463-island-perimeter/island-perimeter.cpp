class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return 1;
        if(grid[i][j] == 2) return 0;
        grid[i][j] = 2;
        int n = 0;
        n += dfs(grid, i+1, j);
        n += dfs(grid, i, j+1);
        n += dfs(grid, i, j-1);
        n += dfs(grid, i-1, j);
        return n;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    count += dfs(grid, i, j);
                    break;
                }
            }
        }
        return count;
    }
};