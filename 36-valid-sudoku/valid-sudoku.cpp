class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row[9], col[9], box[9];
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                int num = board[i][j];
                int boxNum = (i/3)*3+(j/3);
                if(board[i][j] == '.') continue;
                if(col[j].count(num) || row[i].count(num) || box[boxNum].count(num)) return false;
                box[boxNum].insert(num);
                col[j].insert(num);
                row[i].insert(num);
            }
        }
        return true;
    }
};