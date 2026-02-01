class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, pair<int,int>>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({0,{i,j}});
                }
            }
        }
        vector<int> dr = {0,-1,0,1};
        vector<int> dc = {1,0,-1,0};
        int maxTime = 0;
        while(!q.empty()){
            int time = q.front().first;
            auto [r, c] = q.front().second;
            q.pop();
            maxTime = max(maxTime, time);
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc] || grid[nr][nc] != 1) continue;
                vis[nr][nc] = 1;
                q.push({time+1,{nr,nc}});
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return maxTime;
    }
};