class Solution {
public:
    bool recc(vector<int>& matchsticks, int ind, vector<int> &side, int &length){
        if(ind == matchsticks.size()){
            return side[0] == side[1] && side[1] == side[2] && side[2] == side[3];
        }
        for(int i=0; i<4; i++){
            if(side[i] + matchsticks[ind] <= length){
            side[i] += matchsticks[ind];
            if(recc(matchsticks, ind+1, side, length)) return true;
            side[i] -= matchsticks[ind];
            }
            if(side[i] == 0)
                break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        vector<int> side(4, 0);
        for(auto &it: matchsticks){
            sum += it;
        }
        if(sum % 4 != 0) return false;
        sum /= 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if(sum < matchsticks[0]) return false;
        return recc(matchsticks, 0, side, sum);
    }
};