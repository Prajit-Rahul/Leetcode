class Solution {
public:
    void recc(vector<int>& candidates, int target, int ind, vector<int> &temp, vector<vector<int>> &ans){
        if(candidates.size() == ind){
            if(target == 0) ans.push_back(temp);
            return;
        }
        if(target - candidates[ind] >= 0){
            temp.push_back(candidates[ind]);
            recc(candidates, target-candidates[ind], ind, temp, ans);
            temp.pop_back();
        }
        recc(candidates, target, ind+1, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recc(candidates, target, 0, temp, ans);
        return ans;
    }
};