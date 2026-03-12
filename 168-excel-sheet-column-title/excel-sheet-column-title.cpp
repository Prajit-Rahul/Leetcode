class Solution {
public:
    string convertToTitle(int columnNumber) {
        int curr = columnNumber;
        int rem = 0;
        string res = "";
        while(curr > 0){
            int l = (curr-1)%26;
            curr = (curr-1)/26;
            char add = 'A' + l;
            res = add + res;
        }
        // char c;
        // if(curr == 26) c = 'Z';
        // else
        //     c = 'A' + (curr-1);
        // res = c + res;
        return res;
    }
};

// curr = 701/26 = 26 
// l = 701%26 = 25 
// curr = 52/26 = 26 
// l = 52%26 = 25 