class Solution {
public:
    // int characterReplacement(string s, int k) {
    //     int l = 0, r = 0, n = s.length();
    //     vector<int> mp(26,0);
    //     int maxFreq = 0, maxLen = 0;
    //     while(r<n){
    //         maxFreq = max(maxFreq, ++mp[s[r]-'A']);
    //         if((r-l+1) - maxFreq > k){
    //             mp[s[l]-'A']--;
    //             l++;
    //         }
    //         maxLen = max(maxLen, r-l+1);
    //         r++;
    //     }
    //     return maxLen;
    // }
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.length();
        int maxCount = 0, maxFreq = 0;
        unordered_map<char, int> mp;
        while(r < n){
            maxFreq = max(maxFreq, ++mp[s[r]]);
            if((r-l+1) - maxFreq <= k){
                maxCount = max(maxCount, (r-l+1));
            }
            else{
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return maxCount;
    }
};