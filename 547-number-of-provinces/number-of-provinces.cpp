class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis){
        vis[i] = 1;
        for(auto &node: adj[i]){
            if(!vis[node]){
                dfs(node, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>> adj(n+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i != j && isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        vector<int> vis(n+1, 0);
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};