class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n = position.size();
        for(int i=0; i<n; i++){
            cars.push_back({target - position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        int count = 0;
        double maxVal = INT_MIN;
        for(int i=0; i<n; i++){
            double time = (double) cars[i].first / cars[i].second;
            if(maxVal < time){
                count++;
                maxVal = time;
            }
        }
        return count;
    }
};