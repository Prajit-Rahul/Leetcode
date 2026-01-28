class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> pq;
        for(int i=0; i<points.size(); i++){
            auto it = points[i];
            int val = it[0] * it[0] + it[1] * it[1];
            if(i >= k && val < pq.top().first){
                pq.pop();
                pq.push({val, it});
            }
            else if(i < k){
                pq.push({val, it});
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

};