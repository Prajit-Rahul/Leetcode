class Solution {
public:
    bool solve(vector<vector<int>>& grid){
        vector<int> top(100001, 0), bottom(100001, 0);
        int n = grid.size(), m = grid[0].size();
        long long topSum = 0, bottomSum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bottomSum += grid[i][j];
                bottom[grid[i][j]]++;
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                bottomSum -= grid[i][j];
                bottom[grid[i][j]]--;
                topSum += grid[i][j];
                top[grid[i][j]]++;
            }
            if(topSum == bottomSum) return true;
            long long diff = topSum-bottomSum;
            if(diff > 0 && diff < 100000){
                int h = i+1, w = m;
                if(h > 1 && w > 1){
                    if(top[diff]) return true;
                }
                else if(h>1 && w == 1){
                    if(grid[0][0] == diff || grid[i][0] == diff) return true;
                }
                else if(h==1 && w > 1){
                    if(grid[0][0] == diff || grid[0][m-1] == diff) return true;
                }
            }
            diff = bottomSum - topSum;
            if(diff > 0 && diff < 100000){
                int h = n-i-1, w = m;
                if(h > 1 && w > 1){
                    if(bottom[diff]) return true;
                }
                else if(h>1 && w == 1){
                    if(grid[i+1][0] == diff || grid[n-1][0] == diff) return true;
                }
                else if(h==1 && w > 1){
                    if(grid[n-1][0] == diff || grid[n-1][m-1] == diff) return true;
                }
            }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(solve(grid)) return true;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>mat(m,vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mat[j][i]=grid[i][j];
            }
        }
        return solve(mat);
    }
};