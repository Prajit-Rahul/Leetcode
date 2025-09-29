class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        int n = s.length();
        int maxCount = 0, count = 0;
        while(r<n){
            if(mp.find(s[r]) != mp.end()){
                if(mp[s[r]] >= l)
                l = mp[s[r]] + 1;
            }
            int len = r - l + 1;
                mp[s[r]]=r;
                r++;
                maxCount = max(len, maxCount);
        }
        return maxCount;
    }
};