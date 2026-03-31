class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> q;
        int n = operations.size();
        for(auto &it: operations){
            if (it != "C" && it != "D" && it != "+"){
                q.push(stoi(it));
            }
            else if(it == "C"){
                if(!q.empty()) q.pop();
            }
            else if(it == "D"){
                if(!q.empty()){
                    int num = q.top();
                    q.push(num*2);
                }
            }
            else if(it == "+"){
                int num1 = 0, num2 = 0;
                if(!q.empty()){
                    num1 = q.top();
                    q.pop();
                }
                if(!q.empty()){
                    num2 = q.top();
                }
                q.push(num1);
                q.push(num1+num2);
            }
        }

        int ans = 0;
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};