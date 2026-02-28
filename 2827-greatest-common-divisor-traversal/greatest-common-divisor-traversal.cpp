class Solution {
public:
    vector<long long> parent, size1;
    int findPar(int u){
        if(u == parent[u]) return u;
        return parent[u] = findPar(parent[u]);
    }
    void union1(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return;
        if(size1[pu] > size1[pv]){
            size1[pu] += size1[pv];
            parent[pv] = pu;
        }
        else{
            size1[pv] += size1[pu];
            parent[pu] = pv;
        }
    }
    
    vector<int> findFactors(int num){
        vector<int> factors;
        for(int i=2; i*i<=num; i++){
            if(num%i == 0){
                factors.push_back(i);
                while(num%i == 0){
                    num /= i;
                }
            }
        }
        if(num != 1){
            factors.push_back(num);
        }
        return factors;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        // if(n == 1) return true;
        parent.resize(n);
        size1.resize(n, 1);
        for(int i=0; i<n; i++){
            // if(nums[i] == 1) return false;
            parent[i] = i;
        }
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int num = nums[i];
            vector<int> factors = findFactors(num);
            for(auto factor: factors){
                if(mp.find(factor) != mp.end()){
                    union1(i, mp[factor]);
                }
                else{
                    mp[factor] = i;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(findPar(i) != findPar(0)) return false;
        }
        return true;
    }
};