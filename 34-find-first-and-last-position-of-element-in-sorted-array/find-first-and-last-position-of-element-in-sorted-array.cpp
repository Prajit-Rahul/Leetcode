class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, n = nums.size();
        int r = n-1;
        int mid = 0;
        while(l <= r){
            mid = l + (r-l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(l == n || nums[l] != target) return {-1,-1};
        int i = l+1;
        while(i<n && nums[l] == nums[i]) i++;
        return {l, i-1}; 
    }
};