class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto &it: tasks){
            mp[it]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &it: mp){
            pq.push({it.second,it.first});
        }
        int ans=0;
        int k;
        queue<pair<int,int>> q;
        while(!pq.empty()){
            k = n+1;
            while(!pq.empty() && k != 0){
                auto [count, ch] = pq.top();
                pq.pop();
                count--;
                if(count > 0)
                    q.push({count, ch});
                ans++;
                k--;
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
            if(pq.empty()) break;
            ans += k;
        }
        return ans;
    }
};