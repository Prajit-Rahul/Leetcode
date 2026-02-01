class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto &it: prerequisites){
            adjList[it[1]].push_back(it[0]);
        }
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto &it: adjList[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto &it: adjList[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return (count == numCourses);
    }
};