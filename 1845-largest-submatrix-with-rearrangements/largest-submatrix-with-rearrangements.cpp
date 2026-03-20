class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), maxArea = 0;
        // vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1 && i > 0){
                    matrix[i][j] += matrix[i-1][j]; 
                }
            }
        }
        for(int i=0; i<n; i++){
            vector<int> row = matrix[i];
            sort(row.begin(), row.end(), greater<int>());
            for(int j=0; j<m; j++){
                int height = row[j];
                int width = j+1;
                maxArea = max(maxArea, height * width);
            }
        }
        return maxArea;
    }
};