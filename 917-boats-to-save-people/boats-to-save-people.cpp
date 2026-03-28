class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0, r = people.size()-1, count = 0;
        sort(people.begin(), people.end());
        while(l<=r){
            if(people[l] + people[r] <= limit){
                r--;
                l++;
            }
            else if(people[r] <= limit){
                r--;
            }
            count++;
        }
        return count;
    }
};