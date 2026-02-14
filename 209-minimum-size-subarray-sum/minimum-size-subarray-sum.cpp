class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int l=0, r=0, n = nums.size();
        int currSum = 0;
        while(r<n){
            currSum += nums[r];
            while(currSum >= target){
                ans = min(r-l+1, ans);
                currSum = currSum - nums[l];
                l++;
            }
            r++;
        }
        return ans==INT_MAX?0:ans;
    }
};