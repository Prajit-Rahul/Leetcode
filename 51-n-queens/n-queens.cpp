class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(vector<string> &s, int i, int j, const int n){
        int tr = i-1;
        int tc = j-1;
        while(tr >= 0 && tc >= 0){
            if(s[tr][tc] == 'Q') return false;
            tr--, tc--;
        }
        tr = i-1;
        tc = j;
        while(tr >= 0){
            if(s[tr][tc] == 'Q') return false;
            tr--;
        }
        tr = i-1;
        tc = j+1;
        while(tr >= 0 && tc >= 0){
            if(s[tr][tc] == 'Q') return false;
            tr--, tc++;
        }
        return true;
    }
    void recc(vector<string> &s, int row, const int n){
        if(row == n){
            ans.push_back(s);
            return;
        }
        for(int i=0; i<n; i++){
            if(isValid(s, row, i, n)){
                s[row][i] = 'Q';
                recc(s, row+1, n);
                s[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s(n,string(n,'.'));
        recc(s, 0, n);
        return ans;
    }
};