class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto &it: nums){
            set.insert(it);
        }
        int maxi = 0;
        for(auto &it: set){
            if(set.count(it-1)) continue;
            int cnt = 1, num = it;
            while(set.count(num+1)){
                num++;
                cnt++;
            }
            maxi = max(cnt, maxi);
        }
        return maxi;
    }
};