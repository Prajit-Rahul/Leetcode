class KthLargest {
public:
    int n;
    priority_queue<int, vector<int>, greater<int>> minheap;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto &it: nums){
            add(it);
        }
    }
    
    int add(int val) {
        if(minheap.size() < n) minheap.push(val);
        else{
            if(val > minheap.top()){
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */