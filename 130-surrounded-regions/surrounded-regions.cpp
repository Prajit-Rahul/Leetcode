class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c){
        int n = board.size();
        int m = board[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m || board[nr][nc] != 'O') continue;
            board[nr][nc] = 'Y';
            dfs(board, nr, nc);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<board.size(); i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'Y';
                dfs(board , i, 0);
            }
            if(board[i][m-1] == 'O'){
                board[i][m-1] = 'Y';
                dfs(board, i, m-1);  
            }
              
        }   
        for(int j=0; j<board[0].size(); j++){
            if(board[0][j] == 'O'){
                board[0][j] = 'Y';
                dfs(board , 0, j);
            }
            if(board[n-1][j] == 'O'){
                board[n-1][j] = 'Y';
                dfs(board , n-1, j);
            }
        }
        for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            if(board[i][j] == 'Y')
                board[i][j] = 'O';
        }
        }
    }
};