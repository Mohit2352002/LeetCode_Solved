class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int const n = size(costs);
        if(2*candidates + k > n) {
            nth_element(costs.begin(), k + begin(costs), end(costs));
            return accumulate(costs.begin(), k + begin(costs), 0L);
        }
        long long i = 0, j = costs.size() - 1, res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(; i <= j && candidates; --candidates) {
            pq.push({costs[i], i++});
            if (i < j)
                pq.push({costs[j], j--});
        }
        while (--k >= 0) {
            auto [sum, p] = pq.top(); pq.pop();
            res += sum;
            if (i <= j) {
                if (p < i)
                    pq.push({costs[i], i++});
                else 
                    pq.push({costs[j], j--});
            }
        }
        return res;
    }
};













/*
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        long long ans=0;
        int cnt = 0,i=0,j=costs.size()-1;
        while(cnt<k){
            while(pq1.size()<candidates && i<=j) pq1.push(costs[i++]);
            while(pq2.size()<candidates && j>=i) pq2.push(costs[j--]);
            int a=pq1.size()>0?pq1.top():INT_MAX;
            int b=pq2.size()>0?pq2.top():INT_MAX;
            // cout<<a<<" "<<b<<"\n";
            if(a<=b){
                ans+=a;
                pq1.pop();
            }else{
                ans+=b;
                pq2.pop();
            }
            cnt++;
        }
        return ans;
    }
};
*/