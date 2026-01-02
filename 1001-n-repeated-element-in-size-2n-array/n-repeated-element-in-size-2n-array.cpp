class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int prev = -1;
        for(int i=2; i<nums.size(); i++){
            if(nums[i] == nums[i-1] || nums[i] == nums[i-2]) return nums[i];
        }
        return nums[0];
    }
};