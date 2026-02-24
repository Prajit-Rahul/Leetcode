class Solution {
public:
    bool recc(vector<int>& nums, int k, int ind, int curr_sum, int sum, vector<bool> &vis){
        if(k == 1) return true;
        if(curr_sum == sum) return recc(nums, k-1, 0, 0, sum, vis);
        for(int i=ind; i<nums.size(); i++){
            if(vis[i] || nums[i] + curr_sum > sum) continue;
            vis[i] = true;
            if(recc(nums, k, i+1, curr_sum+nums[i], sum, vis)) return true;   
            vis[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(nums.size() < k || sum%k != 0) return false;
        sum /= k;
        vector<bool> vis(nums.size(), false);
        sort(nums.begin(), nums.end(), greater<int>());
        return recc(nums, k, 0, 0, sum, vis);
    }
};