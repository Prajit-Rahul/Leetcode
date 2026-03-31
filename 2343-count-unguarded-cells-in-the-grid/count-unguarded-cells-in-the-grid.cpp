class Solution {
public:
    vector<int> dr = {1,0,-1,0};
    vector<int> dc = {0,1,0,-1};
    void recc(vector<vector<int>> &grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        for(int k=0; k<4; k++){
            int nr = dr[k] + i;
            int nc = dc[k] + j;
            while(nr >= 0 && nc >= 0 && nc < n && nr < m && grid[nr][nc] != 1 && grid[nr][nc] != 2){
                if(grid[nr][nc] == 0)
                    grid[nr][nc] = 3;
                nr += dr[k];
                nc += dc[k];
            }
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(auto &it: guards){
            grid[it[0]][it[1]] = 1;
        }
        for(auto &it: walls){
            grid[it[0]][it[1]] = 2;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    recc(grid, i, j);
            }
        }
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};