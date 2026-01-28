class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> pq;
        for(auto &it: points){
            pq.push({it[0] * it[0] + it[1] * it[1], it});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

};