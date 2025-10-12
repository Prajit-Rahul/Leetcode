class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = accumulate(gas.begin(), gas.end(), 0);
        int costSum = accumulate(cost.begin(), cost.end(), 0);
        if(gasSum < costSum) return -1;
        int start = 0, total = 0;
        for(int i=0; i<gas.size(); i++){
            total += (gas[i] - cost[i]);
            if(total < 0){
                total = 0;
                start = i + 1;
            }
        }
        return start;
    }
};