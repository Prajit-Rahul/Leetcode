class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto &it: wordList){
            st.insert(it);
        }
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        while(!q.empty()){
            string word = q.front().second;
            int count = q.front().first;
            q.pop();
            if(word == endWord) return count;
            for(int i=0; i<word.size(); i++){
                char ch = word[i];
                for(int j=0; j<26; j++){
                    word[i] = 'a' + j;
                    if(st.find(word) != st.end()){
                        q.push({count+1, word});
                        st.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};