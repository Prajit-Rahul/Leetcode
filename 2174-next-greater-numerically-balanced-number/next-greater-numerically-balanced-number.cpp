class Solution {
public:
    void backProp(vector<int> &lists, vector<int> &count, long num){
        if(num > 0 && isBeautiful(count)){
            lists.push_back((int)num);
        }
        if(num > 1224444) return;
        for(int d=1; d<=7; d++){
            if(count[d] < d){
                count[d]++;
                backProp(lists, count, num*10+d);
                count[d]--;
            }
        }
    }
    bool isBeautiful(vector<int> &count){
        for(int d=1; d<=7; d++){
            if(count[d] != 0 && count[d] != d)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        vector<int> lists, count(10, 0);
        backProp(lists, count, 0);
        sort(lists.begin(), lists.end());
        for(auto &it: lists){
            if(it > n){
                return it;
            }
        }
        return -1;
    }
};