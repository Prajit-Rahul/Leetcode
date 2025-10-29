class Solution {
public:
    bool recc(vector<int> &nums, int ind, vector<vector<int>> &dp, int sum){
        if(ind >= nums.size()){
            return false;
        }
        if(sum == 0) return true;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        bool ntake = recc(nums, ind+1, dp, sum);
        bool take = false;
        if(nums[ind] <= sum) take = recc(nums, ind+1, dp, sum - nums[ind]);
        return dp[ind][sum] = (take || ntake);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum%2==1) return 0;
        sum /= 2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return recc(nums, 0, dp, sum);
    }
};