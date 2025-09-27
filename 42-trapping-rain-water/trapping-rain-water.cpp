class Solution {
public:
    int trap(vector<int>& height) {
        int maxRight = INT_MIN, maxLeft = INT_MIN;
        int l = 0, r = height.size()-1, total = 0;
        while(l<r){
            if(height[l] <= height[r]){
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