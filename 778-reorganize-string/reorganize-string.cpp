class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(auto &it: s){
            mp[it]++;
        }
        for(auto &it: mp){
            pq.push({it.second, it.first});
        }
        string str = "";
        while(!pq.empty()){
            auto [count1, node1] = pq.top();
            count1--;
            pq.pop();
            str.push_back(node1);
            if(pq.empty()){ 
                if(count1>0) return "";
                break;
            }
            auto [count2, node2] = pq.top();
            count2--;
            pq.pop();
            str.push_back(node2);
            if(count1>0) pq.push({count1, node1});
            if(count2>0) pq.push({count2, node2});
        }
        return str;
    }
};