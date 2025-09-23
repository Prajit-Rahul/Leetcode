class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size()-2, ans = -1;
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == nums[mid+1]){
                if(mid%2 == 0){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if(mid%2 == 0){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                ans = nums[mid];
            }
        }
        return ans;
    }
};