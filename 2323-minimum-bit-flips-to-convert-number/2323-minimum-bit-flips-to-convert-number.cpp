class Solution {
public:
    int minBitFlips(int start, int goal) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        long  x=start^goal,c=0;
        while(x){
            c+=x&1;
            x=x>>1;
        }
        return c;
    }
};








/*
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        while(start || goal){
            int str_bit=start & 1, goal_bit=goal & 1;
            if(str_bit != goal_bit) ++ans;
            start>>=1;
            goal>>=1;
        }
        return ans;
    }
};*/