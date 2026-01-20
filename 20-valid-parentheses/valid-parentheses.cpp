class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto &it: s){
            if(st.empty() || it == '(' || it == '[' || it == '{'){
                st.push(it);
            }
            else if(st.top() == '('){
                if(it == ')') st.pop();
                else return false;
            }
            else if(st.top() == '{'){
                if(it == '}') st.pop();
                else return false;
            }
            else if(st.top() == '['){
                if(it == ']') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};