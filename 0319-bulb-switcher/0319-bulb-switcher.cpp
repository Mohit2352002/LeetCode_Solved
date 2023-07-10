class Solution {
public:
    int bulbSwitch(int n) {
        if(n<2) return n;
        return (int)(sqrt(n));
    }
};