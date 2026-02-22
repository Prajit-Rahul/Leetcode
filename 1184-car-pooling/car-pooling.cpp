class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stops(1001, 0);
        for(auto &it: trips){
            for(int i=it[1]; i<it[2]; i++){
                stops[i] += it[0];
            }
        }
        int maxi = *max_element(stops.begin(), stops.end());
        return maxi <= capacity;
    }
};