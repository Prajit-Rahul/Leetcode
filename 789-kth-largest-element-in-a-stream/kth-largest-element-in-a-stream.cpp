class KthLargest {
public:
    int n = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto &it: nums){
            add(it);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > n){
            pq.pop();
        }    
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */