class Solution {
public:
    int recc(vector<int> &nums, int target, vector<int> &dp){
        if(target == 0) return 1;
        int take = 0;
        if(dp[target] != -1) return dp[target];
        for(int i=0; i<nums.size(); i++){
            if(target >= nums[i])
                take += recc(nums, target-nums[i], dp);
        }
        return dp[target] = take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, -1);
        return recc(nums, target, dp);
    }
};