class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int> pq;
        int n = nums.size() - k + 1;
        for(auto &it: nums){
            pq.push(it);
            if(pq.size() > n) pq.pop();
        }
        return pq.top();
    }
};