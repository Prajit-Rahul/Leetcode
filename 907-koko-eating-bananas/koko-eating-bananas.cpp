class Solution {
public:
    bool isValid(vector<int> &piles, int h, int k){
        long sum = 0;
        for(int i=0; i<piles.size(); i++){
            sum += (piles[i]+k-1)/k;
        }
        return (h >= sum);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end()), l = 1;
        int mid = 0, ans = 0;
        while(l <= r){
            mid = l + (r-l)/2;
            if(isValid(piles, h, mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};