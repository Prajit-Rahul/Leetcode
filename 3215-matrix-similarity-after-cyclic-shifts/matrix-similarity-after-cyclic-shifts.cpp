class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat[0].size();
        k = k%m;
        vector<vector<int>> nums = mat;
        for(int i=0; i<mat.size(); i++){
            reverse(nums[i].begin(), nums[i].begin()+k);
            reverse(nums[i].begin()+k, nums[i].end());
            reverse(nums[i].begin(), nums[i].end());
        }
        return mat == nums;
    }
};