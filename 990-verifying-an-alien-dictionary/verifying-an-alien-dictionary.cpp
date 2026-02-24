class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int,int> mp;
        for(int i=0; i<order.length(); i++){
            mp[order[i]-'a'] = i;
        }
        for(auto &w: words){
            for(auto &c: w){
                c = mp[c-'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};