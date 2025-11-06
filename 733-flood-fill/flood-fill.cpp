class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int dr[4] = {0,-1,0,1};
        int dc[4] = {1,0,-1,0};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            int prev = image[r][c];
            image[r][c] = color;
            visited[r][c] = 1;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<0 || nc<0 || nr >= n || nc >= m || image[nr][nc] != prev || visited[nr][nc]) continue; 
                q.push({nr,nc});
            }
        }
        return image;
    }
};