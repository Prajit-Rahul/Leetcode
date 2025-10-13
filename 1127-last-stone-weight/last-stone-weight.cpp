class Solution {
public:
    
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &it: stones){
            pq.push(it);
        } 
        while(pq.size() > 1){
            int node1 = pq.top();
            pq.pop();
            int node2 = pq.top();
            pq.pop();
            // if(node1 != node2)
                pq.push(node1 - node2);
        }
        return pq.top();
    }
};