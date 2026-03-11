class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size(), j=0;
        vector<pair<int,int>> queryP;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<n; i++){
            queryP.push_back({queries[i], i}); 
        }
        sort(intervals.begin(), intervals.end());
        sort(queryP.begin(), queryP.end());
        vector<int> res(n, -1);
        for(auto &query: queryP){
            int start = query.first;
            while(j<intervals.size() && intervals[j][0] <= start){
                pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                j++;
            }

            while(!pq.empty() && pq.top().second < start){
                pq.pop();
            }
            if(!pq.empty()){
                res[query.second] = pq.top().first;
            }
        }
        return res;
    }
};