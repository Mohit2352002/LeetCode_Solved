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
};