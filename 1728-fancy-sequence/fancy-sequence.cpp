class Fancy {
public:
    vector<long> nums;
    long add = 0, mul = 1;
    const long MOD = 1e9 + 7;
    Fancy() {
        
    }
    long modInv(long mul){
        long res = 1, p = MOD-2;
        long x = mul;
        while(p){
            if(p&1) res = (res * x) %MOD;
            x = (x*x)%MOD;
            p >>= 1;
        }
        return res;
    }
    void append(int val) {
        long num = (((MOD + val - add)%MOD) * modInv(mul))%MOD;
        nums.push_back(num);
    }
    
    void addAll(int inc) {
        add = (add + (inc%MOD))%MOD;
    }
    
    void multAll(int m) {
        mul = (mul*(m%MOD))%MOD;
        add = (add*(m%MOD))%MOD;
    }
    
    int getIndex(int idx) {
        if(idx < nums.size())
            return ((nums[idx]*mul)%MOD + add)%MOD;
        return -1;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */