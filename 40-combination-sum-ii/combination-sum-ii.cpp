class Solution {
public:
    void recc(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>> &ans, int ind){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<candidates.size(); i++){
            if(i > ind && candidates[i-1] == candidates[i]) continue;
                if(target-candidates[i]>=0){
                    temp.push_back(candidates[i]);
                    recc(candidates, target-candidates[i], temp, ans, i+1);
                    temp.pop_back();
                }
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        recc(candidates, target, temp, ans, 0);
        return ans;
    }
};