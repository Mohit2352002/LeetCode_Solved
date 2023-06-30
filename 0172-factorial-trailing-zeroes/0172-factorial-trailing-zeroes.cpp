class Solution {
public:
    int trailingZeroes(int n) { 
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int count = 0;
        for (long long i = 5; n / i; i *= 5)
            count += n / i;
        return count;
    }
};










/*
class Solution {
public:
    int trailingZeroes(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};*/