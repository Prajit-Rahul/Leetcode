class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = 0, maxRight = 0;
        int l = 0, r = height.size()-1;
        int total = 0;
        while(l<=r){
            if(height[l] < height[r]){
                maxLeft = max(maxLeft, height[l]);
                total += maxLeft - height[l];
                l++;
            }
            else{
                maxRight = max(maxRight, height[r]);
                total += maxRight - height[r];
                r--;
            }
        }
        return total;
    }
};