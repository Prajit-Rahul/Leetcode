class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = 0, currMin = 0, minSum = INT_MAX, maxSum = INT_MIN;
        int total = 0, n = nums.size();
        for(int num: nums){
            total += num;
            currMin = min(num, currMin+num);
            minSum = min(minSum, currMin);
            currMax = max(num, currMax+num);
            maxSum = max(maxSum, currMax);
        }
        if(total - minSum == 0) return maxSum;
        return max(total - minSum, maxSum);
    }
};