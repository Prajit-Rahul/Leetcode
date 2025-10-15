class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> lastEntTime = intervals[0];
        int count = 0, n = intervals.size();
        for(int i=1; i<n; i++){
            if(intervals[i][0] >= lastEntTime[1]){
                count++;
                lastEntTime = intervals[i];
            }
        }
        return n-count-1;
    
    }
};