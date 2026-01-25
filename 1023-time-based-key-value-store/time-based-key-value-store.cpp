class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});        
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = mp[key].size()-1, ind = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(mp[key][mid].second <= timestamp){
                ind = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ind==-1?"":mp[key][ind].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */