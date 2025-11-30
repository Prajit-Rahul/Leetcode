class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, zeros = 0, n = nums.size();
        int ans = 0, count = 0;
        while(i < n){
            if(nums[i] == 0){
                zeros++;
            }
            if(zeros > k){
                if(nums[j] == 0) zeros--;
                j++;
            }
            if(zeros <= k){
                ans = max(ans, i-j+1);
            }
            i++;
        }
        return ans;
    }
};