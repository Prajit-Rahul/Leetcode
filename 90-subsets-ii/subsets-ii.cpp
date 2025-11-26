class Solution {
public:
    vector<vector<int>> ans;
    void recc(vector<int>& nums, int ind, vector<int> &num){
        ans.push_back(num);    
        for(int i=ind; i<nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            num.push_back(nums[i]);
            recc(nums, i+1, num);
            num.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> num;
        recc(nums, 0, num);
        return ans;
    }
};