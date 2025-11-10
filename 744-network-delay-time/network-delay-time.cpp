class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            for(auto &it: adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(wt + edgeWt < dist[adjNode]){
                    dist[adjNode] = wt + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int maxi = 0;
        for(int i=1; i<=n; i++){
            maxi = max(maxi, dist[i]);
        }
        return maxi == INT_MAX?-1:maxi;
    }
};