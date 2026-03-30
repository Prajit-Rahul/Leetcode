class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxi = 0, n = s.length(), maxFreq = 0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[s[r]]++;
            maxFreq = max(mp[s[r]], maxFreq);
            if((r-l+1) - maxFreq <= k){
                maxi = max(r-l+1, maxi);
            }
            else{
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return maxi;
    }
};