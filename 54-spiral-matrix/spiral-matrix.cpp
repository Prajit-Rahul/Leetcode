class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, b = n-1;
        int t = 0, r = m-1;
        vector<int> ans;
        while(l <= r && t <= b){
            for(int i=l; i<=r; i++){
                ans.push_back(matrix[t][i]);
            }
            t++;
            for(int i=t; i<=b; i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(t > b) break; 
            for(int i=r; i>=l; i--){
                ans.push_back(matrix[b][i]);
            }
            b--;
            if(l > r) break;
            for(int i=b; i>=t; i--){
                ans.push_back(matrix[i][l]);
            }
            l++;
        }
        return ans;
    }
};