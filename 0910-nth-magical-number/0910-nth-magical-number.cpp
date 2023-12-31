class Solution {
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a,a);
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        long long low=min(a,b), high=n*low, lcm=(a*b)/gcd(a,b), mod=1e9 + 7,ans;
        while(low<=high){
            long long mid=low+(high-low)/2, factor=(mid/a)+(mid/b)-(mid/lcm);
            if(factor<n) low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans%mod;
    }
};









/*
class Solution {
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a,a);
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        long long low=min(a,b), high=n*low, lcm=(a*b)/gcd(a,b), mod=1e9 + 7;
        while(low<high){
            long long mid=low+(high-low)/2, factor=(mid/a)+(mid/b)-(mid/lcm);
            if(factor<n) low=mid+1;
            else high=mid;
        }
        return high%mod;
    }
};*/