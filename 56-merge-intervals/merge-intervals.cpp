class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); 
        vector<int> temp = intervals[0];
        int i = 0, n = intervals.size()-1;
        vector<vector<int>> ans;
        while(i<n){
            if(temp[1] >= intervals[i+1][0]){
                temp[0] = min(temp[0], intervals[i+1][0]);
                temp[1] = max(temp[1], intervals[i+1][1]);
            }
            else{
                ans.push_back(temp);
                temp = intervals[i+1];
            }
            i++;
        }
        ans.push_back(temp);
        return ans;
    }
};