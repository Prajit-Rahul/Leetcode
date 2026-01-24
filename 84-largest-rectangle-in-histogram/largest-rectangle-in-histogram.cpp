class Solution {
public:
    vector<int> pse(vector<int>& heights){
        int n = heights.size();
        vector<int> ps(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            ps[i] = (st.empty())?-1:st.top();
            st.push(i);
        }
        return ps;
    }
    vector<int> nse(vector<int>& heights){
        int n = heights.size();
        vector<int> ns(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ns[i] = (st.empty())?n:st.top();
            st.push(i);
        }
        return ns;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ps = pse(heights);
        vector<int> ns = nse(heights);
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, heights[i] * (ns[i] - ps[i] - 1));
        }
        return maxi;
    }
};