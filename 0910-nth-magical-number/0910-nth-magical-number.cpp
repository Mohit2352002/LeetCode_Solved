class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        long long low=min(a,b), high=n*low, lcm=(a*b)/__gcd(a,b), mod=1e9 + 7;
        while(low<high){
            long long mid=low+(high-low)/2, factor=(mid/a)+(mid/b)-(mid/lcm);
            if(factor<n) low=mid+1;
            else high=mid;
        }
        return high%mod;
    }
};