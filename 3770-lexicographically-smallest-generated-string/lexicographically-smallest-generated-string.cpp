class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size(), last = -1;
        string str(n+m-1, '?');
        vector<bool> locked(n+m-1, false);
        for(int i=0; i<n; i++){
            if(str1[i] == 'T'){
                for(int j=0; j<m; j++){
                    if(str[j+i] == '?' || str[i+j] == str2[j]){
                        str[i+j] = str2[j];
                        locked[i+j] = true;
                    }
                    else 
                        return "";
                }
            }
        }
        for(char &c : str) {
            if(c == '?') c = 'a';
        }
        for (int i = 0; i < n; i++) {
            if(str1[i] != 'F') continue;
            bool check = true;
            for(int j=0; j<m; j++){
                if(str[i+j] != str2[j]){
                    check = false;
                    break;
                }
            }
            if(!check) continue;
            bool change = true;
            for(int j=m-1; j>=0; j--){
                int pos = i + j;
                if(str[i+j] == str2[j] && !locked[i+j]){
                    str[i+j] = 'b';
                    change = false;
                    break;
                }
            }
            if(change) return "";
        }
        return str;
    }
};