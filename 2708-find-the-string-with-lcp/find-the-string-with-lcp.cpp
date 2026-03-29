class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, 'X');
        int ind = -1;
        for(int i=0; i<n; i++){
            if(lcp[i][i] != n-i) return "";
            if(s[i] >= 'a') continue;
            if(ind >= 25) return "";
            ind++;
            for(int j=i; j<n; j++){
                if(lcp[i][j]){
                    s[j] = 'a'+ind;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                const int x = lcp[i][j];
                if(lcp[j][i] != x) return "";
                if(x + i > n) return "";
                int y = (i < n-1)?lcp[i+1][j+1]:0;
                // y += (s[i] == s[j]);
                y = (s[i] == s[j]) ? y + 1 : 0;
                if(x != y) return "";
            }
        }
        return s;
    }
};