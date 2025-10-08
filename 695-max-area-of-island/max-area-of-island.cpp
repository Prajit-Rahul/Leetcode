class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &count, vector<vector<bool>> &vis){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || !grid[i][j]) return;
        vis[i][j] = true;
        count++;
        dfs(grid, i+1, j, count, vis);
        dfs(grid, i, j+1, count, vis);
        dfs(grid, i-1, j, count, vis);
        dfs(grid, i, j-1, count, vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(!vis[i][j]){
                    int count = 0;
                    dfs(grid, i, j, count, vis);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};