class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        if(n==0) return {};
        else if(n == 1) return {0};
        vector<int> indegree(n, 0);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.clear();
            int size = q.size();
            for(int i=0; i<size; i++){
                int node = q.front();
                q.pop();
                res.push_back(node);
                for(auto &adjNode: adj[node]){
                    indegree[adjNode]--;
                    if(indegree[adjNode] == 1){
                        q.push(adjNode);
                    }
                }
            }
        }
        return res;
    }
};