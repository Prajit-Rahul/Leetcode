class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(n, 0);
        int min_cost = 0;
        unordered_map<int, int> cache;
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            min_cost += cost;
            for(int v=0; v<n; v++){
                if(!vis[v]){
                    int dist = abs(points[v][0] - points[node][0]) + abs(points[v][1] - points[node][1]);
                    if(cache.find(v) == cache.end() || cache[v] > dist){
                        cache[v] = dist;
                        pq.push({dist, v});
                    } 
                }
            }
        }
        return min_cost;
    }
};