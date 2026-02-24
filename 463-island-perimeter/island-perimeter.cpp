class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j){
        int count = 4;
        if(j > 0 && grid[i][j-1] == 1) 
            count--;
        if(i > 0 && grid[i-1][j] == 1)
            count--;
        if(i+1 < grid.size() && grid[i+1][j] == 1) 
            count--;
        if(j+1 < grid[0].size() && grid[i][j+1] == 1) 
            count--;
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    count += dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};