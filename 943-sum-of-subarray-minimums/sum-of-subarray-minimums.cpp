class Solution {
public:
    vector<int> findNSE(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n,0);
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = (st.empty())?n:st.top();
            st.push(i);
        }        
        return nse;
    }
    vector<int> findPSE(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> pse(n,0);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = (st.empty())?-1:st.top();
            st.push(i);
        }        
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        int mod = 1e9+7;
        vector<int> nseList = findNSE(arr);
        vector<int> pseList = findPSE(arr);
        for(int i=0; i<n; i++){
            int nse = nseList[i] - i;
            int pse = i - pseList[i];
            sum = (sum + 0ll + (nse * pse * 1ll * arr[i])%mod)%mod;
        }
        return sum;
    }
};