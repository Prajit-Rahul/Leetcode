class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pair<int,char>> pq;
        if(a != 0) pq.push({a,'a'});
        if(b != 0) pq.push({b,'b'});
        if(c != 0) pq.push({c,'c'});
        while(!pq.empty()){
            auto [count1, ch1] = pq.top();
            pq.pop();
            int n = ans.size();
            if(n > 1 && ans[n-1] == ch1 && ans[n-2] == ch1){
                if(pq.empty()) return ans;
                auto [count2, ch2] = pq.top();
                pq.pop();
                ans.push_back(ch2);
                if(count2>1) pq.push({count2-1, ch2});
                pq.push({count1, ch1});
            }
            else{
                ans.push_back(ch1);
                if(count1 > 1) pq.push({count1-1, ch1});
            }
        }
        return ans;
    }
};