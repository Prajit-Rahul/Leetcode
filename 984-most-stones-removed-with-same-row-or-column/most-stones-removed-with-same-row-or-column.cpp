class Solution {
public:
    int find(vector<int> &parent, int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent, parent[u]);
    }
    void union1(vector<int> &parent, vector<int> &size, int u, int v){
        int u_p = find(parent, u);
        int v_p = find(parent, v);

        if(u_p != v_p){
            if(size[u_p] <= size[v_p]){
                parent[v_p] = parent[u_p];
                size[v_p] = size[u_p];
            }
            else{
                parent[u_p] = parent[v_p];
                size[u_p] = size[v_p];
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0, count = 0;
        for(auto &it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        int m = maxRow + maxCol + 1;
        vector<int> parent(maxRow + maxCol + 2), size(maxRow + maxCol + 2, 1);
        for(int i=0; i<=maxRow + maxCol + 1; i++){
            parent[i] = i;
        }
        unordered_map<int,int> mp;
        for(auto &it: stones){
            int u = it[0];
            int v = maxRow + 1 + it[1];
            union1(parent, size, u, v);
            mp[u] = 1;
            mp[v] = 1;
        }
        for(auto &it: mp){
            if(find(parent, it.first) == it.first){
                count++;
            }
        }
        return stones.size() - count;
    }
};