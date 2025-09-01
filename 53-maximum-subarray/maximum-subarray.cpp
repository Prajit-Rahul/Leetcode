class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currTot = 0, totMax = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            currTot += nums[i];
            if(currTot < nums[i]){
                currTot = nums[i];
            }
            totMax = max(totMax, currTot);
        }
        return totMax;
    }
};