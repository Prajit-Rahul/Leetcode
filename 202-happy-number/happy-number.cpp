class Solution {
public:
    int nextNumber(int n){
        int num = 0;
        while(n!=0){
            int a = n%10;
            num += a*a;
            n /= 10;
        }
        return num;
    }
    bool isHappy(int n) {
        int slow = n, fast = nextNumber(n);
        while(slow != 1 && slow != fast){
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        }
        return slow== 1;
    }
};