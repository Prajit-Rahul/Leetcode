class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        string temp = "";
        for(int i=0; i<=n; i++){
            if(i == n || path[i] == '/'){
                if(temp == ".."){
                    if(!st.empty())
                        st.pop();
                }
                else if(temp != "." && temp.length() != 0){
                    st.push(temp);
                }
                temp = "";
            }
            else if(path[i] != '/'){
                temp += path[i];
            } 
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.size() == 0) return "/";
        return ans;
    }
};