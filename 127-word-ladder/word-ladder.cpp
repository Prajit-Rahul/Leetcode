class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        for(auto &w: wordList){
            mp[w] = 1;
        }
        queue<pair<int,string>> q;
        q.push({1, beginWord});
        while(!q.empty()){
            int len = q.front().first;
            string word = q.front().second;
            q.pop();
            if(word == endWord) return len;
            for(int i=0; i<word.length(); i++){
            char c = word[i];
            for(int j=0; j<26; j++){
                word[i] = 'a'+j;
                if(word[i] == c) continue;
                if(mp[word]){
                    mp[word]--;
                    q.push({len+1, word});
                }
            }
            word[i] = c;
            }
        }
        return 0;
    }
};