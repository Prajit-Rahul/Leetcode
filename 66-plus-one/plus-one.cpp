class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int> ans;
        while(n--){
            int num = digits[n] + carry;
            if(num > 9){
                num = num%10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            ans.push_back(num);
        }
        if(carry > 0) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};