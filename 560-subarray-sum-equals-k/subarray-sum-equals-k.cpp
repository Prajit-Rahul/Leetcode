class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0, preSum = 0;
        mp[0] = 1;
        for(auto &it: nums){
            preSum += it;
            int remove = preSum - k;
            count += mp[remove];
            mp[preSum]++;
        }
        return count;
    }
};