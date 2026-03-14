class Solution {
public:
    string ans = "";
    int count = 0;
    void recc(int n, string &s, char prev){
        if(count == 0) return;
        if(n == 0){
            count--;
            if(count == 0) ans = s;
            return;
        }
        n--;
        if(prev != 'a'){
            s.push_back('a');
            recc(n, s, 'a');
            s.pop_back();
        }
        if(prev != 'b'){
            s.push_back('b');
            recc(n, s, 'b');
            s.pop_back();
        }
        if(prev != 'c'){
            s.push_back('c');
            recc(n, s, 'c');
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string s = "";
        count = k;
        recc(n, s, ' ');
        return ans;
    }
};