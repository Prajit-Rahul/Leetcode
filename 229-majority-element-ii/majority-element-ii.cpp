class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = INT_MIN, num2 = INT_MIN, count1 = 0, count2 = 0;
        for(auto &it: nums){
            if(count1 == 0 && it != num2){
                num1 = it;
                count1 = 1;
            }
            else if(count2 == 0 && it != num1){
                num2 = it;
                count2 = 1;
            }
            else if(it == num1){
                count1++;
            }
            else if(it == num2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = count2 = 0;
        for(auto &it: nums){
            if(num1 == it) count1++;
            if(num2 == it) count2++;
        }
        if(count1 > n/3) ans.push_back(num1);
        if(count2 > n/3) ans.push_back(num2);
        return ans;
       
    }
};