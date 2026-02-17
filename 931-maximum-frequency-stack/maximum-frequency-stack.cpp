class FreqStack {
public:
    unordered_map<int,int> mp;
    unordered_map<int, stack<int>> m;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        maxFreq = max(maxFreq, ++mp[val]);
        m[mp[val]].push(val);
    }
    
    int pop() {
        int val = m[maxFreq].top();
        m[maxFreq].pop();
        mp[val]--;
        if(m[maxFreq].size() == 0){
            maxFreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */