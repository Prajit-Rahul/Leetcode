class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        set<pair<int,int>> seen;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
        int n = grid.size();
        q.push({grid[0][0], 0, 0});
        int dr[4] = {0,1,0,-1};
        int dc[4] = {-1,0,1,0};
        int maxi = 0;
        while(!q.empty()){
            auto [val, i, j] = q.top();
            q.pop();
            if(seen.count({i,j})) continue;
            seen.insert({i,j});
            maxi = max(maxi, val);
            if(i == n-1 && j == n-1) return maxi;
            for(int k=0; k<4; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr < 0 || nc < 0 || nr >= n || nc >= n ) continue;
                q.push({grid[nr][nc], nr, nc});
            }
        }
        return maxi;
    }
};