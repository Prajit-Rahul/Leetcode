class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n = num1.size(), m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> res(n + m, 0);
        for(int i=0; i<num1.size(); i++){
            int a = num1[i] - '0';
            for(int j=0; j<num2.size(); j++){
                int b = num2[j] - '0';
                res[i + j] += a * b;
                res[i+j+1] += res[i+j]/10;
                res[i+j] %= 10;
                
            }
        }
        for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
        if(res.size() > 1 && res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        string ans;
        for (int num : res)
            ans.push_back(num+'0'); 
        return ans;
    }
};