class Solution {
public:
    vector<vector<int>> ans;
    void recc(vector<int>& candidates, int target, int ind, int sum, vector<int> &temp){
        if(sum >= target || ind >= candidates.size()){
            if(sum == target) ans.push_back(temp);
            return;
        }
        recc(candidates, target, ind+1, sum, temp);
        temp.push_back(candidates[ind]);
        recc(candidates, target, ind, sum+candidates[ind], temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        recc(candidates, target, 0, 0, temp);
        return ans;
    }
};