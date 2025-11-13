class Solution {
public:
    int find(vector<int> &parent, int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent, parent[u]);
    }
    void union1(vector<int> &parent, vector<int> &size, int u, int v){
        int pu = find(parent, u);
        int pv = find(parent, v);

        if(pu != pv){
            if(size[pu] > size[pv]){
                size[pu] += size[pv];
                parent[pv] = parent[pu];
            }
            else{
                size[pv] += size[pu];
                parent[pu] = parent[pv];
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {1,-1,0,0};
        int dcol[] = {0,0,1,-1};
        vector<int> size(n*m,0);
        vector<int> parent(n*m);
        for(int i=0; i<n*m; i++){
            parent[i] = i;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int ind = i*m+j;
                if(grid[i][j]) size[ind] = 1;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int ind = i*m+j;
                if(!grid[i][j]) continue;
                for(int k=0; k<4; k++){
                    int nr = i + drow[k];
                    int nc = j + dcol[k];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m || !grid[nr][nc]) continue;
                    int adj = nr*m + nc;
                    union1(parent, size, ind, adj);
                }
            }
        }
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int ind = i*m+j;
                int root = find(parent, ind);
                if(grid[i][j] == 1){
                    maxi = max(maxi, size[root]);
                }
                else{
                    int size1 = 1;
                    set<int> s;
                    for(int k=0; k<4; k++){
                    int nr = i + drow[k];
                    int nc = j + dcol[k];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == 0) continue;
                    int adj = nr*m + nc;
                    int root = find(parent, adj);
                    s.insert(root);
                    }
                    for(auto &it: s){
                        size1 += size[it];
                    }
                    maxi = max(maxi, size1);
                }
            }
        }
        return maxi;
    }
};