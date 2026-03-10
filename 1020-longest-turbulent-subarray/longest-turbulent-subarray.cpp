class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), count = 0, maxCount = 0;
        for(int i=0; i<n; i++){
            if(i >= 2 && ((arr[i-2] < arr[i-1] && arr[i-1] > arr[i]) || (arr[i-1] < arr[i] && arr[i-2] > arr[i-1]))){
                count++;
            }
            else if(i >= 1 && arr[i] != arr[i-1]){
                count = 2;
            }
            else{
                count = 1;
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};