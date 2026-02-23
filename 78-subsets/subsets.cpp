class Solution {
public:
    void recc(vector<int>& nums, int ind, vector<vector<int>> &ans, vector<int>& temp){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        recc(nums, ind+1, ans, temp);
        temp.pop_back();
        recc(nums, ind+1, ans, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        recc(nums, 0, ans, temp);
        return ans;
    }
};