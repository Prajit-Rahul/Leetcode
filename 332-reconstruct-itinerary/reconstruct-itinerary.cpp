class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for(auto &it: tickets){
            mp[it[0]].insert(it[1]);
        }
        stack<string> st;
        st.push("JFK");
        vector<string> ans;
        while(!st.empty()){
            string node = st.top();
            if(mp[node].size() == 0){
                ans.push_back(node);
                st.pop();
            }
            else{
                auto dst = mp[node].begin();
                st.push(*dst);
                mp[node].erase(dst);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};