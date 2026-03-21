class Solution {
public:
    // vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    //     int n = grid.size(), m = grid[0].size();
    //     vector<vector<int>> ans(n-k+1, vector<int>(m-k+1, 0));
    //     multiset<int> st;
    //     for(int i=0; i<k; i++){
    //         for(int j=0; j<k; j++){
    //             st.insert(grid[i][j]);
    //         }
    //     }
    //     for(int i=0; i<=n-k; i++){
    //         for(int j=0; j<=m-k; j++){
    //             vector<int> vals;
    //             for(int x=i; x<i+k; x++){
    //                 for(int y=j; y<j+k; y++){
    //                     vals.push_back(grid[x][y]);
    //                 }
    //             }
    //             sort(vals.begin(), vals.end());
    //             int best = INT_MAX;
    //             if (vals.size() <= 1) {
    //                 ans[i][j] = 0;
    //                 continue;
    //             }
    //             for(int t=1; t<vals.size(); t++){
    //                 if (vals[t] != vals[t-1]) {
    //                     best = min(best, vals[t] - vals[t-1]);
    //                 }
    //             }
    //             ans[i][j] = best;
    //         }
    //     }
    //     return ans;
    // }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1, 0));
        for(int i=0; i<=n-k; i++){
            map<int,int> mp;
            for(int r=i; r<i+k; r++){
                for(int c=0; c<k; c++){
                    mp[grid[r][c]]++;
                }
            }
            for(int j=0; j<=m-k; j++){
                if (mp.size() <= 1) {
                    ans[i][j] = 0;
                }
                else{
                    int best = INT_MAX;
                    auto it = mp.begin();
                    int prev = it->first;
                    ++it;
                    for(;it != mp.end(); it++){
                        best = min(best, abs(it->first - prev));
                        prev = it->first;
                    }
                    ans[i][j] = best;
                }
                if(j<m-k){
                    for(int r=i; r<i+k; r++){
                        mp[grid[r][j]]--;
                        if(mp[grid[r][j]] == 0) mp.erase(grid[r][j]);
                        mp[grid[r][j+k]]++;
                    }
                }
            }
        }
        return ans;
    }
};