class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0, maxLeft = 0, maxRight = 0;
        while(l<r){
            if(height[l] < height[r]){
                maxLeft = max(height[l], maxLeft);
                ans += maxLeft - height[l];
                l++;
            }
            else{
                maxRight = max(height[r], maxRight);
                ans += maxRight - height[r];
                r--;
            }
        }
        return ans;
    }
};