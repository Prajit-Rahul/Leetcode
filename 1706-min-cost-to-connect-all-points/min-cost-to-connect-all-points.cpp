class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int min_cost = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(n, false);
        unordered_map<int,int> cache;
        pq.push({0,0});
        while(!pq.empty()){
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if(visited[u]) continue;
            visited[u] = true;
            min_cost += cost;
            for(int v=0; v<n; v++){
                if(!visited[v]){
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if(cache.find(v) == cache.end() || dist < cache[v]){
                        cache[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }
        return min_cost;
    }
};