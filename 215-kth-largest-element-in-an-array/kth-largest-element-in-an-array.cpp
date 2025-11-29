class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &it: nums){
            pq.push(it);
            if(pq.size() > k){
                pq.pop();
            }
        }
        // int last = 0;
        // while(!pq.empty()){
        //     last = pq.top();
        //     pq.pop();
        // }
        return pq.top();
    }
};