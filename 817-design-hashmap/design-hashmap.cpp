class Node{
    public:
        int key;
        int value;
        Node *next;
    
    Node(int k=-1, int v=-1, Node *n=nullptr): key(k), value(v), next(n) {}
};
class MyHashMap {
public:
    vector<Node *> mp;
    int size = 1000;
    MyHashMap() {
        mp.resize(size);
        for(int i=0; i<1000; i++){
            mp[i] = new Node();
        }
    }
    int hash(int key){
        return key%size;
    }
    void put(int key, int value) {
        int hash_key = hash(key);
        Node *curr = mp[hash_key];
        while(curr->next){
            if(curr->next->key == key){
                curr->next->value = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new Node(key, value);
    }
    
    int get(int key) {
        int hash_key = hash(key);
        Node *curr = mp[hash_key];
        while(curr->next){
            if(curr->next->key == key){
                return curr->next->value;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_key = hash(key);
        Node *curr = mp[hash_key];
        while(curr->next){
            if(curr->next->key == key){
                Node *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */