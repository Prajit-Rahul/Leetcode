class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> open(n+1, 0), close(n+1, 0);
        int j = 0, k = 0;
        for(int i=0; i<n; i++){
            if(customers[n-i-1] == 'Y'){
                j++;
            }
            if(customers[i] == 'N'){
                k++;
            }
            open[n-i-1] = j;
            close[i+1] = k;
        }
        int ansInd = 0, ans = INT_MAX;
        for(int i=0; i<=n; i++){
            int pen = open[i] + close[i];
            if(pen < ans){
                ans = pen;
                ansInd = i;
            }
        }
        return ansInd;
    }
};