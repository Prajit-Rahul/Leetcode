class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        int min_cost = 0;
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            min_cost += cost;
            for(int i=0; i<n; i++){
                int newCost = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
                if(dist[i] > newCost){
                    dist[i] = newCost;
                    pq.push({dist[i], i});
                }
            }
        }
        return min_cost;
    }
};