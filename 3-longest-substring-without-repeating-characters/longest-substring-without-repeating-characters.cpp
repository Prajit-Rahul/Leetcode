class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s == " ") return 0;
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        int n = s.length();
        int maxCount = 0, count = 0;
        while(r<n){
            if(mp.find(s[r]) == mp.end()){
                int len = r - l + 1;
                maxCount = max(len, maxCount);
                mp[s[r]]++;
                r++;
                
            }
            else{
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
        }
        return maxCount;
    }
};