class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ind = 0;
        for(int i=0; i<nums.size(); i++){
            if(ind < i){
                return false;
            }
            ind = max(ind, i+nums[i]);
            cout<<"i = "<<i<<", ind = "<<ind<<endl;
        }
        return true;
    }
};