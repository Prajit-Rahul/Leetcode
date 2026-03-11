class Solution {
public:
    int candy(vector<int>& ratings) {
        int i = 1, n = ratings.size(), sum = 1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++, sum++;
            }
            int top = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                top++;
                sum += top;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i] < ratings[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > top){
                sum += down - top;
            }
        }
        
        return sum;
    }
};