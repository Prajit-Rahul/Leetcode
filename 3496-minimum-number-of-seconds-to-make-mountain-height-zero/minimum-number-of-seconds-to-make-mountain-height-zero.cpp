class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans = 0;
        int n = workerTimes.size();
        priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>> pq;
        for(int i=0; i<n; i++){
            pq.push({workerTimes[i], {i,1}});
        }
        vector<int> workTime(n, 0);
        for(int i=0; i<mountainHeight; i++){
            long long time = pq.top().first;
            auto [worker, ht] = pq.top().second;
            pq.pop();
            ans = time;
            pq.push({time + 1ll*(ht+1)*workerTimes[worker], {worker, ht+1}});
        }
        return ans;
    }
};