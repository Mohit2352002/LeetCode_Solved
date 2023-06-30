class Solution {
public:
    bool isHappy(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(n==1) return true;
        else if(n==7) return true;
        else if(n<10) return false;
        long long int sum=0;
        while(n>=10){
            while(n){
                int digit= n%10;
                n/=10;
                sum+=1ll*digit*digit;
            }
            if(sum==1 || sum==7) return true;
            n=sum;
            sum=0;
        }
        return false;
    }
};