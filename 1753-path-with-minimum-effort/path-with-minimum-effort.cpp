class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> q;
        q.push({0, {0,0}});
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {-1,0,1,0};
        while(!q.empty()){
            int i = q.top().second.first;
            int j = q.top().second.second;
            int currAbs = q.top().first;
            q.pop();
            if(i==n-1 && j == m-1) return currAbs;
            for(int k=0; k<4; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                int newAbs = abs(heights[i][j] - heights[nr][nc]);
                newAbs = max(newAbs, currAbs);
                if(newAbs < dist[nr][nc]){
                    dist[nr][nc] = newAbs;
                    q.push({newAbs,{nr, nc}});
                }
            }
        }
        return -1;
    }
};