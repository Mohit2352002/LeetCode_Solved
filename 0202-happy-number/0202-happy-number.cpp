/*
//Floyd cycle detection algo using slow and fast pointer
class Solution {
public:
    int next(int n)
    {
        int sum = 0;
        
        while(n != 0)
        {
            sum += pow(n % 10,2);
            n = n / 10;
        }
        
        return sum;
    }

public:
    bool isHappy(int n) {
        
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int slow = next(n);
        int fast = next(next(n));
        
        while(slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        
        return fast == 1 ;
    }
};
*/










class Solution {
public:
    bool isHappy(int n) {

        if(n==1 || n==7) return true;
        else if(n<10) return false;

        long long int sum;

        while(n>=10){
            sum=0;
            while(n){
                int digit= n%10;
                n/=10;
                sum+=1ll*digit*digit;
            }
            if(sum==1 || sum==7) return true;
            else n=sum;
        }

        return false;
    }
};













/*
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> tmp;
        
        while(n != 1)
        {
            if(tmp[n] == 0)
                tmp[n]++;
            else
                return false;
            
            int sum = 0;
            while(n != 0)
            {
                sum += pow(n % 10,2);
                n = n / 10;
            }
            
            n = sum;
        }
        
        return true;
    }
};
*/