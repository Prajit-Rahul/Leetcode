class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        int i = n;
        while(i--){
            if(i == n-1){
                v[i]++;
            }
            if(v[i] == 10){
                v[i] = 0;
                if(i != 0){
                    v[i-1]++;
                }
                else{
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        return v;
    }
};