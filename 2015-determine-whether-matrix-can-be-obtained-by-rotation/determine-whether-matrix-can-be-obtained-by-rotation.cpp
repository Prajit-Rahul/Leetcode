class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = target.size(), m = target[0].size();
        for(int k = 0; k < 4; k++){
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        if(mat == target) return true;
        }
        return false;
    }
};