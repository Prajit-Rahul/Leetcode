class Solution {
public:
    // int recc(vector<int> &nums, int ind, vector<int> &dp){
    //     if(ind < 0) return 0;
    //     if(dp[ind] != -1) return dp[ind];
    //     int take = recc(nums, ind-1, dp);
    //     int ntake = recc(nums, ind-2, dp) + nums[ind];
    //     return dp[ind] = max(take, ntake);
    // }
    // int rob(vector<int>& nums) {
    //     vector<int> temp;
    //     vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
    //     if(1 == nums.size()) return nums[0];
    //     for(int i=1; i<nums.size(); i++){
    //         temp.push_back(nums[i]);
    //     }
    //     int res1 = recc(temp, temp.size()-1, dp1);
    //     nums.pop_back();
    //     int res2 = recc(nums, nums.size()-1, dp2);
    //     return max(res1, res2);
    // }
    // int recc(vector<int> &nums, int l, int r){
    //     vector<int> dp(nums.size(), 0);
    //     for(int ind=l; ind<=r; ind++){
    //         int take = (ind-1>=0)?dp[ind-1]:0;
    //         int ntake = (ind-2>=0)?dp[ind-2]:0;
    //         ntake += nums[ind];
    //         dp[ind] = max(take, ntake);
    //     }
    //     return dp[r];
    // }
    int recc(vector<int> &nums, int l, int r){
        int prev1 = 0, prev2 = 0, curr = 0;
        for(int ind=l; ind<=r; ind++){
            int take = (ind-1>=0)?prev1:0;
            int ntake = (ind-2>=0)?prev2:0;
            ntake += nums[ind];
            curr = max(take, ntake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int res1 = recc(nums, 0, nums.size()-2);
        int res2 = recc(nums, 1, nums.size()-1);
        return max(res1, res2);
    }
};