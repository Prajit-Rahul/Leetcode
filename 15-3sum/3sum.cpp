class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int l = i+1, r = nums.size()-1;
            int val = nums[i];
            while(l<r){
                int tot = nums[l] + nums[r] + val;
                if(tot == 0){
                    ans.push_back({nums[l], nums[r], val});
                    l++;
                    r--;
                    while(l < r && nums[l-1] == nums[l]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r+1]){
                        r--;
                    }
                }
                else if(tot<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};