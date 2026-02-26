class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n+1);
        for(auto &time: times){
            adjList[time[0]].push_back({time[1], time[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        q.push({0, k});
        while(!q.empty()){
            int node = q.top().second;
            int currTime = q.top().first;
            q.pop();
            for(auto &adj: adjList[node]){
                int adjNode = adj.first;
                int adjTime = adj.second;
                if(dist[adjNode] > adjTime + currTime){
                    dist[adjNode] = adjTime + currTime;
                    q.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans, dist[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};