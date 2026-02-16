class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        long long sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
            sum += nums[i];
        }
        vector<int> vis(n, 0);
        vector<long long> ans;
        for(auto &it: queries){
            if(vis[it[0]] == 0){
                vis[it[0]] = 1;
                sum -= nums[it[0]];
            }
            int count = it[1];
            while(!pq.empty() && count != 0){
                int node = pq.top().first;
                int ind = pq.top().second;
                pq.pop();
                if(!vis[ind]){
                    vis[ind] = 1;
                    sum -= node;
                    count--;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};