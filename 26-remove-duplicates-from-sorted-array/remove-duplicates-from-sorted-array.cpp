class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, count = 1;
        while(r<n){
            if(nums[l] != nums[r]){
                l++;
                nums[l] = nums[r];
                count++;
            }
            r++;
        }
        return count;
    }

};