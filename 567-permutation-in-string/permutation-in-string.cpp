class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0), freq2(26, 0);
        int k = s1.length(), n = s2.length(), match = 0;
        int l = 0, r = k;
        if(n<k) return false;
        for(int i=0; i<k; i++){
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq1[i] == freq2[i])
                match++;
        }
        if(match == 26) return true;
        while(r<n){
            freq2[s2[l] - 'a']--;
            if(freq2[s2[l] - 'a'] == freq1[s2[l] - 'a']) match++;
            else if(freq2[s2[l] - 'a'] + 1 == freq1[s2[l] - 'a']) match--;
            freq2[s2[r] - 'a']++;
            if(freq2[s2[r] - 'a'] == freq1[s2[r] - 'a']) match++;
            else if(freq2[s2[r] - 'a'] - 1 == freq1[s2[r] - 'a']) match--;
            if(match == 26) return true;
            l++, r++;
        }
        return false;
    }
};