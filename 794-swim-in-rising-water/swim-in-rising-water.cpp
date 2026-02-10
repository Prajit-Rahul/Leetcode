class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        set<pair<int,int>> seen;
        vector<int> dr = {1,0,-1,0};
        vector<int> dc = {0,-1,0,1};
        int n = grid.size(), m = grid[0].size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({grid[0][0], 0, 0});
        int maxi = 0;
        while(!pq.empty()){
            auto [ht, i, j] = pq.top();
            pq.pop();
            if(seen.count({i, j})) continue;
            seen.insert({i, j});
            maxi = max(ht, maxi);
            if(i == n-1 && j == m-1) return maxi;
            for(int k=0; k<4; k++){
                int r = i + dr[k];
                int c = j + dc[k];
                if(r < 0 || c < 0 || r >= n || c >= m) continue;
                pq.push({max(ht, grid[r][c]), r, c});
            }
        }
        return maxi;
    }
};