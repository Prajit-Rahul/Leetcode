class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.length();
        int len = 0, maxLen = 0;
        unordered_map<char,int> mp;
        while(r<n){
            if(mp.find(s[r]) == mp.end()){
                len = r-l+1;
                mp[s[r]]++;
                r++;
                maxLen = max(len, maxLen);
            }
            else{
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
        }
        return maxLen;
    }
};