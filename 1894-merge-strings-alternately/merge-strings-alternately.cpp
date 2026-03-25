class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        string s="";
        for(int i=0; i<max(n, m); i++){
            if(i<n) s.push_back(word1[i]);
            if(i<m) s.push_back(word2[i]);
        }
        return s;
    }
};