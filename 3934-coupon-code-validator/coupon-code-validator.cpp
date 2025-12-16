class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,vector<string>> mp;
        for(int i=0; i<code.size(); i++){
            bool check = true;
            if(!isActive[i]) continue;
            if(code[i].empty()) continue;
            for(auto &it: code[i]){
                if(!(isalnum(it) || it == '_')){
                    check = false;
                    break;
                }
            }
            if(check){
                mp[businessLine[i]].push_back(code[i]);
            }
        }
        vector<string> ans;
        vector<string> allowed = {"electronics", "grocery", "pharmacy", "restaurant"};
        for(auto &bis: allowed){
            auto it = mp.find(bis);
            if (it == mp.end()) continue;
            auto &v = it->second;
            sort(v.begin(), v.end());  
                for(auto &s: v){
                    ans.push_back(s);
                }
        }
        return ans;
    }
};