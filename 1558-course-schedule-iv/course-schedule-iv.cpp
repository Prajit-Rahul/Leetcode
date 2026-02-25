class Solution {
public:
    vector<unordered_set<int>> mp;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjCourses(numCourses);
        for(auto &it: prerequisites){
            adjCourses[it[1]].push_back(it[0]);
        }
        mp.resize(numCourses);
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
        if(!mp[node].empty()) return mp[node];
        for(auto &adj: adjCourses[node]){
            auto adjSt = dfs(adjCourses, adj);
            mp[node].insert(adjSt.begin(), adjSt.end());
            mp[node].insert(adj);
        }
        return mp[node];
    }
};