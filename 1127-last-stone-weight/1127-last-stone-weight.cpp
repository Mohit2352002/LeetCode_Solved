class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=stones.size();
        if(n==1) return stones[0];
        priority_queue<int>pq;
        for(int el:stones){
            pq.push(el);
        }
        int x,y;
        while(!pq.empty() and pq.size()>1){
            y=pq.top(); pq.pop();
            x=pq.top(); pq.pop();
            if(x==y) continue;
            else pq.push(y-x);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};