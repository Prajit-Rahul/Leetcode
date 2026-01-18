class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int l = 0, r = height.size()-1;
        while(l<r){
            int val = min(height[l], height[r]) * (r-l);
            maxi = max(val, maxi);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return maxi;
    }
};