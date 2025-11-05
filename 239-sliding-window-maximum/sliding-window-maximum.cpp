class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int l = 0, r = 0;
        int n = nums.size();
        vector<int> ans;
        while(r<n){
            while(!q.empty() && q.front() < l){
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()] <= nums[r]){
                q.pop_back();
            }
            q.push_back(r);
            if(r >= k-1){
                ans.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }
        return ans;
    }
};