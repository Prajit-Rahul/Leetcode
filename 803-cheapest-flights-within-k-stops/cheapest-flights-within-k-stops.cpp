class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        // priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        queue<pair<int,pair<int,int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        pq.push({0,{src, 0}});
        while(!pq.empty()){
            // int u = pq.top().second.first;
            // int stops = pq.top().second.second;
            // int wt = pq.top().first;
            int u = pq.front().second.first;
            int stops = pq.front().second.second;
            int wt = pq.front().first;
            pq.pop();
            if(stops > k) continue;
            for(auto &it: adj[u]){
                int edgeWt = it.second;
                int v = it.first;
                if(wt + edgeWt < dist[v] && stops <= k){
                    dist[v] = wt + edgeWt;
                    pq.push({dist[v], {v, stops+1}});
                }
            }
        }
        return dist[dst]==INT_MAX ? -1:dist[dst]; 
    }
};