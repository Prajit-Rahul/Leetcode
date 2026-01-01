class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n;
        while(i--){
            if(i == n-1){
                digits[i]++;
            }
            if(digits[i] == 10){
                digits[i] = 0;
                if(i == 0){
                    digits[i] = 1;
                    digits.push_back(0);
                }
                else{
                    digits[i-1]++;
                }
            }
        }
        return digits;
    }
};