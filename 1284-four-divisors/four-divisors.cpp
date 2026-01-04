class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto &num: nums){
            int count = 2, temp = 0;
            for(int i=2; i*i<=num; i++){
                if(num%i == 0){
                if(i*i!=num){
                    count+=2;
                    temp += i;
                    temp += num/i;
                }
                else{
                    count++;
                    temp += i;
                }
                }
            }
            if(count == 4){
                ans += temp;
                ans += num;
                ans++;
            }
        }
        return ans;
    }
};