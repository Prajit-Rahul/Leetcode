class Solution {
public:
    bool binary(vector<vector<int>>& matrix, int &target, int &ind, int l, int r){
        int mid = 0;
        while(l<=r){
            mid = l + (r-l)/2;
            if(matrix[ind][mid] == target){
                cout<<matrix[ind][mid];
                return true;
            }
            else if(matrix[ind][mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        cout<<matrix[ind][mid];
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1, ind = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[mid][0] <= target){
                ind = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return binary(matrix, target, ind, 0, matrix[0].size()-1);
    }
};