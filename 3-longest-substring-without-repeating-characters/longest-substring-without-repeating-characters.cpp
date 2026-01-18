class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     int l = 0, r = 0, maxLen = 0;
    //     int n = s.length();
    //     unordered_map<char, int> mp;
    //     while(r<n){
    //         if(mp.find(s[r]) == mp.end()){
    //             mp[s[r]]++;
    //         }
    //         else{
    //             while(mp[s[r]] > 0){
    //                 mp.erase(s[l]);
    //                 l++;
    //             }
    //             mp[s[r]]++;
    //         }
    //         maxLen = max(maxLen, r - l + 1);
    //         r++;
    //     }
    //     return maxLen;
    // }
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxLen = 0;
        int n = s.length();
        unordered_map<char, int> mp;
        while(r<n){
            if(mp.find(s[r]) != mp.end()){
                l =  max(l, mp[s[r]] + 1);
            }
            maxLen = max(maxLen, r - l + 1);
            mp[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};