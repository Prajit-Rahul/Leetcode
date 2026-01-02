class Solution {
public:
    unordered_map<string, vector<char>> mp;

    bool dfs(string &bottom, int i, string &temp){
        if(bottom.size() == 1) return true;
        if(i == bottom.size()-1){
            string tem;
            return dfs(temp, 0, tem);
        }
        string key = bottom.substr(i,2);
        for(char v: mp[key]){
            temp.push_back(v);
            if(dfs(bottom, i+1, temp)) return true;
            temp.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        string temp;
        for(auto &it: allowed){
            mp[it.substr(0,2)].push_back(it[2]);
        }
        return dfs(bottom, 0, temp);
    }
};