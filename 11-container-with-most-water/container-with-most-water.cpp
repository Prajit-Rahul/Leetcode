class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxi = 0;
        while(l<r){
            int area = (r-l) * min(height[l], height[r]);
            maxi = max(area, maxi);
            if(height[r] < height[l]) r--;
            else l++;
        }
        return maxi;
    }
};