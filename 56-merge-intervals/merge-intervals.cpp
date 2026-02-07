class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        int i= 0, n = intervals.size();
        for(int i=0; i<n-1; i++){
            if(intervals[i+1][0] <= temp[1]){
                temp[0] = min(intervals[i+1][0], temp[0]);
                temp[1] = max(intervals[i+1][1], temp[1]);
            }
            else{
                ans.push_back(temp);
                temp = intervals[i+1];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};