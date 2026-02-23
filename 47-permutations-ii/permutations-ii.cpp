class Solution {
public:
    void recc(unordered_map<int,int> &mp, vector<vector<int>> &ans, int ind, vector<int> &temp){
        if(ind < 0){
            ans.push_back(temp);
            return;
        }
        for(auto &it: mp){
            if(it.second > 0){
                temp.push_back(it.first);
                mp[it.first]--;
                recc(mp, ans, ind-1, temp);
                mp[it.first]++;
                temp.pop_back();
            }
        }
        // for(int i=ind; i<nums.size(); i++){
        //     if(i>ind && nums[i] == nums[ind]) continue;
        //     swap(nums[i], nums[ind]);
        //     recc(nums, ans, ind+1);
        //     swap(nums[i], nums[ind]);
        // }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        vector<int> temp;
        for(auto &it: nums){
            mp[it]++;
        }
        recc(mp, ans, nums.size()-1, temp);
        return ans;
    }
};