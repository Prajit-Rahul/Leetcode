class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> mp1, mp2;
        if(trust.size() == 0 && n == 1) return 1;
        for(auto &it: trust){
            mp1[it[1]]++;
            mp2[it[0]]++;
        }
        for(auto &it: mp1){
            if(it.second == n-1 && mp2.find(it.first) == mp2.end())
                return it.first;
        }
        return -1;
    }
};