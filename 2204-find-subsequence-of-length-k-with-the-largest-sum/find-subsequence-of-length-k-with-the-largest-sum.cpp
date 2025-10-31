class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &it: nums){
            if(pq.size() < k){
                pq.push(it);
            }
            else if(pq.top() < it){
                pq.pop();
                pq.push(it);
            }
        }
        vector<int> ans;
        unordered_map<int, int> mp;
        while(!pq.empty()){
            mp[pq.top()]++;
            pq.pop();
        }
        for(auto &it: nums){
            if(mp.find(it) != mp.end()){
                ans.push_back(it);
                mp[it]--;
                if(mp[it] == 0) mp.erase(it);
            }
        }
        return ans;
    }
};