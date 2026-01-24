class Solution {
public:
    bool isValid(vector<int>& piles, int h, int k){
        int n = piles.size();
        long count = 0;
        for(auto &it: piles){
            count += (it + k - 1)/k;
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h < piles.size()) return -1;
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int maxi = 0, ind = r;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isValid(piles, h, mid)){
                ind = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ind;
    }
};