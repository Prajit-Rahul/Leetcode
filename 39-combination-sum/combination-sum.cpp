class Solution {
public:
    vector<vector<int>> ans;
    void recc(vector<int>& candidates, int target, int ind, vector<int> &temp){
        if(ind >= candidates.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }
        recc(candidates, target, ind+1, temp);
        if(target - candidates[ind] >= 0){
            temp.push_back(candidates[ind]);
            recc(candidates, target-candidates[ind], ind, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        recc(candidates, target, 0, temp);
        return ans;
    }
};