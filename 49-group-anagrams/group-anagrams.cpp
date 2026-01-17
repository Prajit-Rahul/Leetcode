class Solution {
public:
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<pair<unordered_map<char, int>, vector<string>>> store;
    //     for(auto &str: strs){
    //         unordered_map<char,int> mp;
    //         for(auto &c: str){
    //             mp[c]++;
    //         }
    //         bool found = false;
    //         for(auto &it: store){
    //             if(it.first == mp){
    //                 it.second.push_back(str);
    //                 found = true;
    //             }
    //         }
    //         if(!found){
    //             store.push_back({mp, {str}});
    //         }
    //     }
    //     vector<vector<string>> ans;
    //     for(auto &it: store){
    //         ans.push_back(it.second);
    //     }
    //     return ans;
    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> v;
        for(auto &str: strs){
            string key = str;
            sort(key.begin(), key.end());
            v[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto &it: v){
            result.push_back(it.second);
        }
        return result;
    }
};