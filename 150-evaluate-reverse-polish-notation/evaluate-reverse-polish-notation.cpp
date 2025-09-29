class Solution {
public:
    long solve(long long a, long long b, char op){
        if(op == '+') return a+b;
        else if(op == '-') return a-b;
        else if(op == '*') return a*b;
        else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(auto &it: tokens){
            if(it == "-" || it == "+" || it == "/" || it == "*"){
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(solve(b, a, (char)it[0]));
            }
            else {
            st.push(stoll(it)); 
        }
        }
        return st.top();
    }
};