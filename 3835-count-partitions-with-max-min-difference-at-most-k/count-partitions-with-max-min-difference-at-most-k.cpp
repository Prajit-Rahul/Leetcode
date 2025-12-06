class Solution {
public:
    int mod = 1e9+7;
    // int recc(vector<int>& nums, int k, int ind, vector<int> &dp){
    //     int count = 0;
    //     if(ind == nums.size()){
    //         return 1;
    //     }
    //     if(dp[ind] != -1) return dp[ind];
    //     int mini = nums[ind], maxi = nums[ind];
    //     for(int j=ind; j<nums.size(); j++){
    //         mini = min(mini, nums[j]);
    //         maxi = max(maxi, nums[j]);
    //         if(maxi - mini > k) break;
    //         count = (count + recc(nums, k, j+1, dp))%mod;
    //     }
    //     return dp[ind] = count;
    // }
    // int countPartitions(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> dp(n, -1);
    //     return recc(nums, k, 0, dp);
    // }
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n+1, 0), prefix(n+1, 0);
        multiset<int> s;
        dp[0] = prefix[0] = 1;
        int j = 0;
        for(int i=0; i < n; i++){
            s.insert(nums[i]);
            while(j<=i && (*s.rbegin() - *s.begin()) > k){
                s.erase(s.find(nums[j]));
                j++;
            }
            if(j > 0){
                dp[i+1] = (prefix[i] - prefix[j-1] + mod) % mod;
            }
            else{
                dp[i+1] = prefix[i]%mod;
            }
            prefix[i+1] = (prefix[i] + dp[i+1])%mod;
        }
        return dp[n];
    }
};