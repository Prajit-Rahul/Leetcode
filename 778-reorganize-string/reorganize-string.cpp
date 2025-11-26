class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char,int> mp;
        for(auto &it: s){
            mp[it]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto &it: mp){
            pq.push({it.second, it.first});
        }
        while(pq.size()>1){
            auto [val1, ch1] = pq.top();
            pq.pop();
            auto [val2, ch2] = pq.top();
            pq.pop();
            if(ch1 == ch2) return "";
            if(val1 > 1) pq.push({val1-1, ch1});
            if(val2 > 1) pq.push({val2-1, ch2});
            ans.push_back(ch1);
            ans.push_back(ch2);
        }
        if(!pq.empty()) {
            if(pq.top().first > 1) return "";
            auto [val1, ch1] = pq.top();
            pq.pop();
            ans.push_back(ch1);
        }
        return ans;
    }
};