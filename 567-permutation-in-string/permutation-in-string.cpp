class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1, mp2;
        int k = s1.length();
        for(auto &it: s1){
            mp1[it]++;
        }
        for(int i=0; i<s2.length(); i++){
            mp2[s2[i]]++;
            if(i >= k){
                mp2[s2[i-k]]--;
                if(mp2[s2[i-k]] == 0) mp2.erase(s2[i-k]);
            }
            if(mp1 == mp2) return true;
        }
        return false;
    }
};