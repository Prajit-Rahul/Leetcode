class MyCircularQueue {
public:
    int arr[1000];
    int l = -1, r = -1;
    int size = 0;
    MyCircularQueue(int k) {
        size = k;
    }
    
    bool enQueue(int val) {
        if(l == -1 && r == -1){
            l = r = 0;
            arr[r] = val;
        } 
        else if(r == size-1){
            if(l == 0) return false;
            else{
                r = 0;
                arr[r] = val;
            }
        }
        else{
            if(r+1 == l) return false;
            else{
                r++;
                arr[r] = val;
            }
        }
        return true;
    }
    
    bool deQueue() {
        if(l == -1 && r == -1) return false;
        else if(l == size-1 && r != size-1){
            l = 0;
        }
        else if(l == size-1){
            l = r = -1;
        }
        else if(l == r){
            l = r = -1;
        }
        else{
            l++;
        }
        return true;
    }
    
    int Front() {
        if(l == -1 && r == -1) return -1;
        return arr[l];
    }
    
    int Rear() {
        if(l == -1 && r == -1) return -1;
        return arr[r];
    }
    
    bool isEmpty() {
        if(l == -1 && r == -1) return true;
        return false;
    }
    
    bool isFull() {
        if(r+1 == l || (l == 0 && r == size-1)) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */