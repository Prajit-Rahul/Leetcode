class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1] == '1') return false;
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(0);
        int start = 0, end = 0, farthest = 0;
        while(!q.empty()){
            int ind = q.front();
            if(ind == n-1) return true;
            q.pop();
            start = max(farthest, ind + minJump);
            end = min(ind + maxJump, n-1);
            for(int i=start; i<=end; i++){
                if(s[i] == '0') q.push(i);
            }
            farthest = end+1;
        }
        return false;
    }
};