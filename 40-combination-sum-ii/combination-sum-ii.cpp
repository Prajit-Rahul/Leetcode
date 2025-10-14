class Solution {
public:
    vector<vector<int>> ans;
    void recc(vector<int>& candidates, int target, int ind, vector<int> &temp){
        if(target <= 0 || ind >= candidates.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }
        for(int j=ind; j<candidates.size(); j++){
            if(j > ind && candidates[j] == candidates[j-1]) continue;
            temp.push_back(candidates[j]);
            recc(candidates, target-candidates[j], j+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        recc(candidates, target, 0, temp);
        return ans;
    }
};