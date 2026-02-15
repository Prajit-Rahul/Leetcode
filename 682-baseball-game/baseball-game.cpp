class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto &it: operations){
            if(it == "C" && !st.empty()){
                st.pop();
            }
            else if(it == "D" && !st.empty()){
                int num = st.top()*2;
                st.push(num);
            }
            else if(it == "+" && st.size() > 1){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2);
                st.push(num1);
                st.push(num1+num2);
                
            }
            else if(it != "D" || it != "C"){
                st.push(stoi(it));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};