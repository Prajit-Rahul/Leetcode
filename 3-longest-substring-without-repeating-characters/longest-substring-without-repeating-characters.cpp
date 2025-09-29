class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1);
        int l = 0, r = 0, n = s.length();
        int maxCount = 0;
        while(r < n){
            unsigned char c = static_cast<unsigned char>(s[r]);
            if(mp[c] != -1){
                if(mp[c] >= l){
                    l = mp[c] + 1;
                }
            }
            mp[c] = r;
            maxCount = max(r - l + 1, maxCount);
            r++;
        }
        return maxCount;
    }
};