class TrieNode{
    public:
        bool end = false;
        TrieNode *childs[26];
    
    TrieNode(){
        for(int i=0; i<26; i++){
            childs[i] = NULL;
        }
    }
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        int idx = 0;
        TrieNode *node = root;
        for(auto &c: word){
            idx = c - 'a';
            if(!node->childs[idx]){
                node->childs[idx] = new TrieNode();
            }
            node = node->childs[idx];
        }
        node->end = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        return search(word, 0, node);
    }

    bool search(string &word, int idx, TrieNode *node){
        if(!node) return false;
        if(idx == word.size()) return node->end;
        if(word[idx] != '.')
            return search(word, idx+1, node->childs[word[idx]-'a']);
        for(int key = 0; key<26; key++){
            if(search(word, idx+1, node->childs[key]))
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */