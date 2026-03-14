class Solution {
public:
    bool recc(int n, string &s, char prev, string &ans, int &k){
        if(n == 0){
            k--;
            if(k == 0){
                ans = s;
                return true;
            }
            return false;
        }
        for(char c: {'a', 'b', 'c'}){
            if(prev != c){
                s.push_back(c);
                if(recc(n-1, s, c, ans, k)) return true;
                s.pop_back();
            }
        }
        return false;
    }
    string getHappyString(int n, int k) {
        string s = "";
        string ans = "";
        recc(n, s, ' ', ans, k);
        return ans;
    }
};