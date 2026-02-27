class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& matrix, int k){
        vector<vector<int>> adjList(k);
        for(auto &it: matrix){
            adjList[it[0]-1].push_back(it[1]-1);
        }
        vector<int> indegree(k, 0);
        vector<int> order;
        for(auto &it: matrix){
            indegree[it[1] - 1]++;
        }
        queue<int> q;
        for(int i=0; i<k ;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(auto &it: adjList[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(order.size() != k) return {};
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder, colOrder;
        vector<vector<int>> res(k, vector<int> (k,0));
        rowOrder = topoSort(rowConditions, k);
        colOrder = topoSort(colConditions, k);
        if(rowOrder.empty() || colOrder.empty())
            return {};
        unordered_map<int, int> mp1, mp2;
        for(int i=0; i<k; i++){
            mp1[rowOrder[i]] = i;  
            mp2[colOrder[i]] = i;  
        }
        for(int j=0; j<k; j++){
            res[mp1[j]][mp2[j]] = j+1;
        }
        return res;
    }
};