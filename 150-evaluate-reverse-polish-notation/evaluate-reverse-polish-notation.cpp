class Solution {
public:
    int solve(int a, int b, string c){
        if(c == "+") return a+b;
        else if(c == "-") return a-b;
        else if(c == "*") return a*b;
        else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &it: tokens){
            if(it != "+" && it != "-" && it != "/" && it != "*"){
                st.push(stoll(it));
            }
            else{
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int res = solve(num2, num1, it);
                st.push(res);
            }
        }
        return st.top();
    }
};