class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n=nums.size();
        vector<int>minCostAti(n,INT_MAX);
        long long ans=LLONG_MAX;
        for(int operation=0; operation<n; ++operation){
            long long curr_cost=1LL*operation*x; //rotation cost
            int idx=0;
            while(idx<n){
                minCostAti[idx]=min(minCostAti[idx],nums[(idx-operation+n)%n]);
                curr_cost+=minCostAti[idx++];
            }
            ans=min(ans,curr_cost);
        }
        return ans;
    }
};