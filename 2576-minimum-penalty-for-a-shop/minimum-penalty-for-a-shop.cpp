class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> open(n+1, 0), close(n+1, 0);
        int minPen = n, currPen = 0;
        for(auto &it: customers){
            if(it == 'Y'){
                currPen++;
            }
        }
        if(minPen > currPen){
            minPen = currPen;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            auto it = customers[i];
            if(it == 'Y'){
                currPen--;
            }
            else{
                currPen++;
            }
            if(minPen > currPen){
                minPen = currPen;
                ans = i+1;
            }
        }
        return ans;
    }
};