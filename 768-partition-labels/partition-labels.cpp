class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int size = 0, end = 0;
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]] = i;
        }
        for(int i=0; i<s.length(); i++){
            end = max(end, mp[s[i]]);
            size++;
            if(end == i){
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};