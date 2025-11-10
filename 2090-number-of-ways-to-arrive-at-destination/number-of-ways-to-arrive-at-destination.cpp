#define ll long long
#define pll pair<long, long>
class Solution {
public:
    ll MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<ll> dist(n, LLONG_MAX);
        vector<ll> ways(n, 0);
        vector<vector<pll>> adj(n);
        for(auto &it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();
            if (wt > dist[node]) continue; 
            for(auto &it: adj[node]){
                ll edgeWt = it.second;
                ll adjNode = it.first;
                if(wt + edgeWt < dist[adjNode]){
                    dist[adjNode] = wt + edgeWt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(wt + edgeWt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};