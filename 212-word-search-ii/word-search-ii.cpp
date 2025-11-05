class Trie{
    public:
    bool end = false;
    Trie *childs[26];
        
    Trie(){
        for(int i=0; i<26; i++){
            childs[i] = NULL;
        }
    }
    
        
};
class Solution {
public:
    Trie *root = new Trie();
    int n;
    int m;
    vector<string> ans;

    Solution(){
        root = new Trie();
    }
    void insert(string &word){
        Trie *node = root;
        for(auto &w: word){
            int idx = w - 'a';
            if(!node->childs[idx])
                node->childs[idx] = new Trie();
            node = node->childs[idx];
        }
        node->end = true;
    }
    void dfs(vector<vector<char>>& board, int i, int j, string &s, Trie *node){
        int c = board[i][j];
        if(c == '#' || !node->childs[c-'a']) return;
        board[i][j] = '#';
        s.push_back(c);
        if(node->childs[c-'a']->end == true){
            ans.push_back(s);
            node->childs[c-'a']->end = false;
        }
        if(i > 0) dfs(board, i-1, j, s, node->childs[c-'a']);
        if(j > 0) dfs(board, i, j-1, s, node->childs[c-'a']);
        if(i < n-1) dfs(board, i+1, j, s, node->childs[c-'a']);
        if(j < m-1) dfs(board, i, j+1, s, node->childs[c-'a']);
        s.pop_back();
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        for(auto &w: words){
            insert(w);
        }
        string s = "";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dfs(board, i, j, s, root);
            }
        }
        return ans;
    }
};