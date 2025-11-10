class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        int dr[] = {0,1,-1,0};
        int dc[] = {1,0,0,-1};
        q.push({0,{0,0}});
        dis[0][0] = 0;
        while(!q.empty()){
            int r = q.top().second.first;
            int c = q.top().second.second;
            int wt = q.top().first;
            q.pop();
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                int effort = max(wt, abs(heights[r][c] -  heights[nr][nc]));
                if(dis[nr][nc] > effort){
                    dis[nr][nc] = effort;
                    q.push({dis[nr][nc] , {nr, nc}});
                }
            }
        }
        return dis[n-1][m-1];
    }
};