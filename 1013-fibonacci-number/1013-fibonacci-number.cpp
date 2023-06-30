class Solution {
public:
    int fib(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(n==1 || n==0) return n;
        return fib(n-1)+fib(n-2);
    }
};