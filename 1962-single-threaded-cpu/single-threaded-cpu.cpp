class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size(), ind = 0;
        for(int i=0; i<n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        long long time = tasks[ind][0];
        vector<int> ans;
        while(ind<n || !pq.empty()){
            while(ind<n && time>=tasks[ind][0]){
                pq.push({tasks[ind][1], tasks[ind][2]});   
                ind++;
            }
            if(pq.empty()){
                time = tasks[ind][0];
            }
            else{
                int ind = pq.top().second;
                ans.push_back(ind);
                time += pq.top().first;
                pq.pop();
            }
        }
        return ans;
    }
};