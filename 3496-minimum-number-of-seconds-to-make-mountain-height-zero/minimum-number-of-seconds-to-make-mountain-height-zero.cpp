class Solution {
public:
    long long block(long long time, int t){
        long long val = (2 * time)/t;
        long long k = (sqrt(1 + 4 * val) - 1)/2;
        return k;
    }
    bool can(long long time, int mountainHeight, vector<int>& workerTimes){
        long long height = 0;
        for(int t: workerTimes){
            height += block(time, t);
            if(height >= mountainHeight) return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 10e15;
        int n = workerTimes.size();
        while(left < right){
            long long mid = left + (right-left)/2;
            if(can(mid, mountainHeight, workerTimes)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return right;
    }
    // long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    //     long long ans = 0;
    //     int n = workerTimes.size();
    //     priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>> pq;
    //     for(int i=0; i<n; i++){
    //         pq.push({workerTimes[i], {i,1}});
    //     }
    //     vector<int> workTime(n, 0);
    //     for(int i=0; i<mountainHeight; i++){
    //         long long time = pq.top().first;
    //         auto [worker, ht] = pq.top().second;
    //         pq.pop();
    //         ans = time;
    //         pq.push({time + 1ll*(ht+1)*workerTimes[worker], {worker, ht+1}});
    //     }
    //     return ans;
    // }
};