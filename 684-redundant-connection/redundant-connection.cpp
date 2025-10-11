class Solution {
public:
    int find(int u, vector<int> &parent){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u], parent);
    }
    void union1(vector<int> &parent, vector<int> &size, int u, int v){
        int pu = find(u, parent);
        int pv = find(v, parent);
        if(size[pu] > size[pv]){
            size[pu] += size[pv];
            parent[pu] = pv;
        }
        else{
            size[pv] += size[pu];
            parent[pv] = pu;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> size(n+1, 1);
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
        for(auto &it: edges){
            if(find(it[0], parent) == find(it[1], parent)) return {it[0], it[1]};
            union1(parent, size, it[0], it[1]);
        }
        return {};
    }
};