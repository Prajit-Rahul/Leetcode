class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        vector<string> ans;
        int n = tickets.size();
        for(auto &it: tickets){
            adj[it[0]].insert(it[1]);
        }
        string s = "JFK";
        stack<string> mystack;
        mystack.push(s);
        while(!mystack.empty()){
            string src = mystack.top();
            if(adj[src].size() == 0){
                ans.push_back(src);
                mystack.pop();
            }
            else{
                auto dst = adj[src].begin();
                mystack.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};