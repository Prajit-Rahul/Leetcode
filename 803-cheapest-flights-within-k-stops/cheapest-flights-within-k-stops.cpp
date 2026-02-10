class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        // if(k==0) return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int wt = q.front().second.second;
            q.pop();
            if(stops > k) continue;
            for(auto &it: adj[node]){
                int edgeWt = it.second;
                int adjNode = it.first;
                if(wt + edgeWt < dist[adjNode]){
                    dist[adjNode] = wt + edgeWt ;
                    q.push({stops+1,{adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};