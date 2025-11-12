class Solution {
public:
    int find(vector<int> &parent, int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent, parent[u]);
    }
    void union1(vector<int> &parent, vector<int> &size, int u, int v){
        int u_p = find(parent, u);
        int v_p = find(parent, v);
        if(size[u_p] <= size[v_p]){
            parent[v_p] = parent[u_p];
            size[v_p] += size[u_p];
        }
        else{
            parent[u_p] = parent[v_p];
            size[u_p] += size[v_p];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        vector<int> parent(n, 0);
        vector<int> size(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int count = 0;
        for(auto &it: connections){
            if(find(parent, it[0]) != find(parent, it[1])){
                union1(parent, size, it[0], it[1]);
                count++;
            }
        }
        if(m >= n-1) return n-count-1;
        return -1;
    }
};