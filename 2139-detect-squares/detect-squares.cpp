class DetectSquares {
public:
    map<pair<int,int>, int> mp;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int count = 0;
        for(auto &it: mp){
            int x = it.first.first;
            int y = it.first.second;
            if(x1 != x && y1 != y && abs(x1 - x) == abs(y1 - y)){
                int f1 = mp[{x1, y}];
                int f2 = mp[{x, y1}];
                int f3 = mp[{x, y}];
                count += f1*f2*f3;
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */