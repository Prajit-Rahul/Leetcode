class Solution {
public:
    bool isValid(vector<int>& weights, int days, int mid){
        int sum = 0, count = 1;
        for(auto &wt: weights){
            if(sum + wt <= mid){
                sum += wt;
            }
            else{
                sum = wt;
                count++;
            }
        }
        return (count <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);
        int ans = h;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(isValid(weights, days, mid)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};