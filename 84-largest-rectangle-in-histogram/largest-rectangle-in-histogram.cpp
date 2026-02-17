class Solution {
public:
    vector<int> nseList(vector<int> &heights){
        int n = heights.size();
        vector<int> nse(n, 0);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            nse[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> pseList(vector<int> &heights){
        int n = heights.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            pse[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nseList(heights);
        vector<int> pse = pseList(heights);
        int n = heights.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            int curr = (nse[i] - pse[i] - 1) * heights[i];
            maxi = max(curr, maxi);
        }
        return maxi;
    }
};