class Solution {
public:
    bool isPowerOfTwo(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(n<=0) return false;
        return __builtin_popcountll(n)==1;
    }
};