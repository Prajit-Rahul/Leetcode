class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = num1.length(), m = num2.length();
        vector<int> arr(n+m, 0);
        for(int i=0; i<n; i++){
            int d1 = num1[i] - '0';
            for(int j=0; j<m; j++){
                int d2 = num2[j] - '0';
                arr[i+j] += d1*d2;
                if(arr[i+j] >= 10){
                    arr[i+j+1] +=  arr[i+j]/10;
                    arr[i+j] %= 10;
                }
            }
        }
        string ans = "";
        int i = n+m-1;
        while(i>=0 && arr[i] == 0)i--;
        for(;i>=0 ; i--){
            ans.push_back(arr[i]+'0');
        }
        return ans;
    }
};