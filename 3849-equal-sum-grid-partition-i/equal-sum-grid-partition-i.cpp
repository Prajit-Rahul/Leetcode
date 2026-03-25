class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum += grid[i][j];
            }
        }
        if(sum%2 == 1) return false;
        long long target = sum/2;
        long long s = 0;
        for(int i=0; i<n-1; i++){
            long long curr = 0;
            for(int j=0; j<m; j++){
                curr += grid[i][j];
            }
            s += curr;
            if(s == target) return true;
        }
        s = 0;
        for(int j=0; j<m-1; j++){
            long long curr = 0;
            for(int i=0; i<n; i++){
                curr += grid[i][j];
            }
            s += curr;
            if(s == target) return true;
        }
        return false;
    }
};