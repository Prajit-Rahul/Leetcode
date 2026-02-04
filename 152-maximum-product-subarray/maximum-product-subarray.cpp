class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suff = 1, maxi = INT_MIN;
        for(int i=0; i<n; i++){
            pre = (pre?pre:1) * nums[i];
            suff = (suff?suff:1) * nums[n-i-1];
            maxi = max({pre, suff, maxi});
        }
        return maxi;
    }
};