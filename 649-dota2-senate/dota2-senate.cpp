class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        for(int i=0; i<senate.size(); i++){
            if(senate[i] == 'R') q1.push(i);
            else q2.push(i);
        }
        int n = senate.size();
        while(!q1.empty() && !q2.empty()){
            int ind1 = q1.front();
            int ind2 = q2.front();
            q1.pop(), q2.pop();
            if(ind1 > ind2) q2.push(ind1+n);
            else q1.push(ind2+n);
        }
        if(q1.size() > q2.size()) return "Radiant";
        return "Dire";
    }
};