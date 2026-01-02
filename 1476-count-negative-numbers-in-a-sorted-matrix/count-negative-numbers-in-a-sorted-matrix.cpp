class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto &it: grid){
            int n = it.size();
            int l = 0, r = n-1;
            int ind = n;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(it[mid] < 0){
                    ind = mid;
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            ans += (n - ind);
        }
        return ans;
    }
};