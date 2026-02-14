class Solution {
public:
    bool isPal(string &nums, int l, int r){
        while(l<=r){
            if(nums[l] != nums[r]) return false;
                l++, r--;
        }
        return true;
    }
    bool validPalindrome(string nums) {
        int l = 0, r = nums.length()-1;
        bool flag = true;
        while(l<=r){
            if(nums[l] == nums[r]){
                l++, r--;
            }
            else if(nums[l] == nums[r-1] || nums[l+1] == nums[r]){
                return isPal(nums, l, r-1) || isPal(nums, l+1, r);
            }
            else{
                return false;
            }
        }
        return true;
    }
};