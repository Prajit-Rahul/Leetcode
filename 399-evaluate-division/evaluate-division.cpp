class Solution {
public:
    
    unordered_map<string, vector<pair<string, double>>> buildGraph(vector<vector<string>>& equations, vector<double>& values){
        unordered_map<string, vector<pair<string, double>>> mp;
        for(int i=0; i<equations.size(); i++){
            const string &dividend = equations[i][0];
            const string &divisor = equations[i][1];
            double val = values[i];
            mp[dividend].push_back({divisor, val});
            mp[divisor].push_back({dividend, (double)1.0/val});
        }
        return mp;
    }
    bool dfs(string src, string dst, unordered_map<string, vector<pair<string, double>>> &mp, double &prod, unordered_set<string> &visited){
        if(src == dst) return true;
        visited.insert(src);
        for(auto &adj: mp[src]){
            string ne = adj.first;
            double val = adj.second;
            if(visited.find(ne) != visited.end()) continue;
            double temp = prod;
            prod *= val;
            if(dfs(ne, dst, mp, prod, visited)) return true;
            prod = temp;
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp = buildGraph(equations, values);
        vector<double> ans;
        for(auto &it: queries){
            double prod = 1.0;
            unordered_set<string> visited;
            if(mp.find(it[0]) == mp.end() || mp.find(it[1]) == mp.end()){
                ans.push_back(-1.0);
            }
            else if(dfs(it[0], it[1], mp, prod, visited)){
                ans.push_back(prod);
            }
            else{
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};