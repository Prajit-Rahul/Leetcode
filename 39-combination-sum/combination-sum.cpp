class Solution {
public:
    void recc(vector<int>& candidates, int target, int ind, vector<vector<int>> &ans, vector<int> &temp){
        if(ind == candidates.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }
        if(target >= candidates[ind]){
            temp.push_back(candidates[ind]);
            recc(candidates, target-candidates[ind], ind, ans, temp);
            temp.pop_back();
        }
        recc(candidates, target, ind+1, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recc(candidates, target, 0, ans, temp);
        return ans;
    }
};