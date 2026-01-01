class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int> ans;
        int i=0;
        if(digits[n-1] == 9){
            for(i=n-1; i>=0; i--){
            if(digits[i] == 9){
                carry = 1;
                digits[i] = 0;
            }
            else{
                carry = 0;
                digits[i]++;
                break;
            }
            }
        }
        else{
            digits[n-1]++;
        }
        if(i == -1 && carry == 1){
            ans.push_back(1);
        }
        for(auto &it: digits){
            ans.push_back(it);
        }
        return ans;
    }
};