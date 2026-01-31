class Solution {
public:
    vector<int> dc = {-1,0,1,0};
    vector<int> dr = {0,1,0,-1};
    bool recc(vector<vector<char>>& board, string word, int r, int c, int ind, vector<vector<bool>> &vis){
        if(ind == word.length()){
            return true;
        }
        // bool k = false;
        for(int k=0; k<4; k++){
            int nr = dr[k] + r;
            int nc = dc[k] + c;
            if(nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size() || vis[nr][nc] ||  board[nr][nc] != word[ind]) continue;
            vis[nr][nc] = 1;
            // k = k || recc(board, word, nr, nc, ind+1, vis);
            if(recc(board, word, nr, nc, ind+1, vis)) return true;
            vis[nr][nc] = 0;
        }
        return false;
        // return k;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[0] == board[i][j]){
                    vector<vector<bool>> vis(n, vector<bool>(m, false));
                    vis[i][j] = 1;
                    if(recc(board, word, i, j, 1, vis)) return true; 
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};