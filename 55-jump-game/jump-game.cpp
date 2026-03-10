class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        while(l<=r && r<n){
            r = max(r, l+nums[l]);
            l++;
        }
        return (r>=n-1);
    }
};