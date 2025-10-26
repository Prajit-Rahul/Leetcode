class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int prev1 = 0, prev2 = nums[0];
        for(int i=1; i<n-1; i++){
            int take = nums[i];
            if(i-2>=0) take += prev1;
            int ntake = prev2;
            prev1 = prev2;
            prev2 = max(take, ntake);
        }
        int prev3 = 0, prev4 = nums[1];
        for(int i=2; i<n; i++){
            int take = nums[i];
            if(i-2>=0) take += prev3;
            int ntake = prev4;
            prev3 = prev4;
            prev4 = max(take, ntake);
        }
        return max(prev2, prev4);
    }
};