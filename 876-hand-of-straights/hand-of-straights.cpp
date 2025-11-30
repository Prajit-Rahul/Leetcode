class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto &it: hand){
            mp[it]++;
        }
        while(!mp.empty()){
            int start = mp.begin()->first;
            for(int i = 0; i<groupSize; i++){
                int val = start + i;
                if(mp.find(val) != mp.end()){
                    mp[val]--;
                    if(mp[val] == 0){
                        mp.erase(val);
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};