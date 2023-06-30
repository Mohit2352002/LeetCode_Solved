class Solution {
public:
    int reachNumber(int target) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(target<0){
            target=-target;
        }
        int step=0;
        int sum=0;
        while(true)
        {
            step++;
            sum=sum+step;
            if(sum==target)
            {
                return step;
            }
            else if(sum>target && (sum-target)%2==0)
            {
                return step;
            }
        }
        return step;
    }
};









/*
//bfs TLE
class Solution {
public:
    int reachNumber(int target) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        queue<int>q;
        q.push(0);
        int count=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int curr=q.front();
                q.pop();
                if(curr==target) return count-1;
                q.push(curr+count);
                q.push(curr-count);
            }
            count++;
        }
        return count;
    }
};*/