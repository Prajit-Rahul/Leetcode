class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mini = INT_MAX;
        mini = min(nums[n-2] - nums[1], nums[n-1] - nums[2]);
        mini = min(mini, nums[n-3]-nums[0]);
        return mini;
    }
};