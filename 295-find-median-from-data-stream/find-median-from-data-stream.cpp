class MedianFinder {
public:
    priority_queue<int> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqMax.empty() || num < pqMax.top()){
            pqMax.push(num);
        }
        else{
            pqMin.push(num);
        }
        if(pqMin.size() > pqMax.size()){
            pqMax.push(pqMin.top());
            pqMin.pop();
        }
        else if(pqMin.size() + 1 < pqMax.size()){
            pqMin.push(pqMax.top());
            pqMax.pop();
        }
    }
    
    double findMedian() {
        if(pqMin.size() == pqMax.size()) 
            return (double)(pqMax.top() + pqMin.top())/2.0;
        return pqMax.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */