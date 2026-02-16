class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        int n = position.size();
        for(int i=0; i<position.size(); i++){
            v.push_back({target - position[i], speed[i]});
        }
        sort(v.begin(), v.end());
        int count = 0;
        double currMax = 0;
        for(auto &it: v){
            double time = (double)it.first/it.second;
            if(currMax < time){
                count++;
                currMax = time;
            }
        }
        return count;
    }
};