class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, steps = 0;
        while(r<n-1){
            int fartherest = 0;
            for(int i=l; i<=r; i++){
                fartherest = max(i+nums[i], fartherest);
            }
            l = r+1;
            r = fartherest;
            steps++;
        }
        return steps;
    }
};