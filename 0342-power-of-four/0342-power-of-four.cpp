class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        float a=log(n)/log(4);
        return a==ceil(a);
    }
};