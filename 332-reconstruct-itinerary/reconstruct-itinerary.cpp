class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for(auto &it: tickets){
            mp[it[0]].insert(it[1]);
        }
        stack<string> st;
        st.push("JFK");
        vector<string> res;
        while(!st.empty()){
            string node = st.top();
            if(mp[node].size() == 0){
                res.push_back(node);
                st.pop();
            }
            else{
                auto nxt = mp[node].begin();
                st.push(*nxt);
                mp[node].erase(nxt);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};