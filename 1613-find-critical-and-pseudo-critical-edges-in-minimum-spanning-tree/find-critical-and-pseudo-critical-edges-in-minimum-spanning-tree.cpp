class Solution {
public:
    vector<long long> size1, parent;
    int findPar(int u){
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);
    }
    void union1(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(size1[pu] < size1[pv]){
            size1[pv] += size1[pu];
            parent[pu] = pv;
        }
        else{
            size1[pu] += size1[pv];
            parent[pv] = pu;
        }
    }
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical, pseudo;
        for(int i = 0; i < edges.size(); i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), cmp);
        int mst = findMST(n, edges, -1, -1);
        for(int i=0; i<edges.size(); i++){
            if(mst < findMST(n, edges, i, -1)){
                critical.push_back(edges[i][3]);
            }
            else if(mst == findMST(n, edges, -1, i)){
                pseudo.push_back(edges[i][3]);
            }
        }
        return {critical, pseudo};
    }

    int findMST(int n, vector<vector<int>>& edges, int block, int include){
        int wt = 0;
        parent.resize(n);
        size1.resize(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        if(include != -1){
            wt += edges[include][2];
            union1(edges[include][0], edges[include][1]);
        }

        for(int i=0; i<edges.size(); i++){
            if(i == block) continue;
            if(findPar(edges[i][0]) == findPar(edges[i][1])) continue;
            union1(edges[i][0], edges[i][1]);
            wt += edges[i][2];
        }
        for(int i=0; i<n; i++){
            if(findPar(0) != findPar(i)) return INT_MAX;
        }
        return wt;
    }
};