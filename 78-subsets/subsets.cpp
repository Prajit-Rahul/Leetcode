class Solution {
public:
    void recc(vector<int>& nums, int i, vector<int> &num, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(num);
            return;
        }
        num.push_back(nums[i]);
        recc(nums, i+1, num, ans);
        num.pop_back();
        recc(nums, i+1, num, ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> num;
        recc(nums, 0, num, ans);
        return ans;
    }
};