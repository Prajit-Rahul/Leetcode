class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, n = nums.size();
        int r = n-2;
        if(nums.size() == 1 || nums[l] > nums[l+1]) return l;
        if(nums[r] < nums[r+1]) return r+1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[mid+1] && nums[mid-1] < nums[mid]) return mid;
            else if(nums[mid] < nums[mid+1]) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};