class Solution {
public:
    // vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    //     vector<vector<int>> adjCourses(numCourses);
    //     for(auto &it: prerequisites){
    //         adjCourses[it[1]].push_back(it[0]);
    //     }
    //     vector<int> indegree(numCourses, 0);
    //     for(int i=0; i<numCourses; i++){
    //         for(auto &it: adjCourses[i]){
    //             indegree[it]++;
    //         }
    //     }
    //     queue<int> q;
    //     for(int i=0; i<numCourses; i++){
    //         if(indegree[i] == 0) q.push(i);
    //     }
    //     int count = 0;
    //     unordered_map<int,int> mp;
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();
    //         mp[node] = count;
    //         count++;
    //         for(auto &it: adjCourses[node]){
    //             indegree[it]--;
    //             if(indegree[it] == 0) q.push(it);
    //         }
    //     }
    //     vector<bool> ans;
    //     for(auto &it: queries){
    //         ans.push_back(it[0] < it[1]);
    //     }
    //     return ans;
    // }

    unordered_map<int, unordered_set<int>> mp;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjCourses(numCourses);
        for(auto &it: prerequisites){
            adjCourses[it[1]].push_back(it[0]);
        }
        
        for(int i=0; i<numCourses; i++){
            dfs(adjCourses, i);
        }
        vector<bool> ans;
        for(auto &it: queries){
            ans.push_back(mp[it[1]].count(it[0]));
        }
        return ans;
    }
    unordered_set<int> dfs(vector<vector<int>> &adjCourses, int node){
        if(mp.count(node) > 0) return mp[node];
        mp[node] = unordered_set<int>();
        for(auto &adj: adjCourses[node]){
            auto adjSt = dfs(adjCourses, adj);
            mp[node].insert(adjSt.begin(), adjSt.end());
            mp[node].insert(adj);
        }
        return mp[node];
    }
};