class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.length();
        int maxi = 0;
        unordered_map<char, int> mp;
        while(r<n){
            if(mp.find(s[r]) != mp.end()){
                l = max(l, mp[s[r]]+1);
            }
            maxi = max(maxi, r - l + 1);
            mp[s[r]] = r;
            r++;
        }
        return maxi;
    }
};