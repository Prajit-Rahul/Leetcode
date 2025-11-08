class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(color[i] != -1) continue;
        q.push(i);
        color[i] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &adj: graph[node]){
                if(color[adj] == -1){
                    q.push(adj);
                    color[adj] = !color[node];
                }
                else if(color[adj] == color[node]){
                    return false;
                }
            }
        }
        }
        return true;
    }
};