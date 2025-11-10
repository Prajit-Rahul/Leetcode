class Solution {
public: 
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dr[8] = {-1,0,1,-1,0,1,-1,1};
        int dc[8] = {1,1,1,-1,-1,-1,0,0};
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        queue<pair<int,pair<int, int>>> q;
        if(grid[0][0]) return -1;
        q.push({1, {0,0}});
        dis[0][0] = 1;
        while(!q.empty()){
            int i = q.front().second.first;
            int j = q.front().second.second;
            int len = q.front().first;
            q.pop();
            for(int k=0; k<8; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr >=n || nc >= m || nr<0 || nc<0 || grid[nr][nc]) continue;
                if(len + 1 < dis[nr][nc]){
                    dis[nr][nc] = len + 1;
                    q.push({dis[nr][nc], {nr, nc}});
                }
            }
        }
        return dis[n-1][m-1] == INT_MAX?-1:dis[n-1][m-1];
    }
};