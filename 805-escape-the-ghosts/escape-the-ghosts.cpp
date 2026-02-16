class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int val = abs(target[0]) + abs(target[1]);
        int mini = INT_MAX;
        for(auto &it: ghosts){
            mini = min(mini, abs(it[0] - target[0]) + abs(it[1] - target[1]));
        }
        return val < mini;
    }
};