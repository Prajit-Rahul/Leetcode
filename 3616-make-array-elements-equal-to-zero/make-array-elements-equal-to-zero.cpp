class Solution {
public:
    bool check(vector<int> nums, int i, int flag){
        vector<int> arr = nums;
        int n = nums.size();
        while(i >= 0 && i < n){
            if(arr[i] > 0){
                arr[i]--;
                flag = !flag;
            }
            if(flag == 1){
                i++;
            }
            else{
                i--;
            }
        }
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum == 0) return 1;
        return 0;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), count = 0;
        vector<int> ind;
        for(int j=0; j<n; j++){
            if(nums[j] == 0){
                count += check(nums, j, 0);
                count += check(nums, j, 1);
            }
        }
        return count;
    }
};