class Solution {
public:
    bool binary(vector<vector<int>>& matrix, int target, int ind){
        int l = 0, r = matrix[0].size() - 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[ind][mid] == target) return true;
            else if(matrix[ind][mid] <= target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return false;
    } 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int l = 0, r = n-1, ind = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[mid][0] <= target){
                ind = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return binary(matrix, target, ind);
    }
};