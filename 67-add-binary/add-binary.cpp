class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int l1 = a.length(), l2 = b.length(), j = 0, carry = 0;
        if(l2>l1){
            swap(a, b);
            l1 = l2;
        }
        while(b.size() < a.size()){
            b = '0' + b;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0; i<l1; i++){
            int digit1 = a[i] - '0';
            int digit2 = b[i] - '0';
            int sum = digit1 + digit2 + carry;
            carry = sum/2;
            sum %= 2;
            ans.push_back(sum + '0');
        }
        if(carry) ans.push_back(carry + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};