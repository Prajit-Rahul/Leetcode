class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second.first;
            int wt = q.front().second.second;
            q.pop();
            if(k < steps) continue;
            for(auto &adjVal: adj[node]){
                int adjNode = adjVal.first;
                int adjDist = adjVal.second;
                if(dist[adjNode] > adjDist + wt){
                    dist[adjNode] = adjDist + wt;
                    q.push({steps+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};