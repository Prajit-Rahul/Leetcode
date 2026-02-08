class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> temp = intervals[0];
        int n = intervals.size(), count = 1;
        for(int i=1; i<n; i++){
            if(temp[1] <= intervals[i][0]){
                count++;
                temp = intervals[i];
            }
        }
        return n-count;
    }
};