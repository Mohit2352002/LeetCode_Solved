class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        int mincost[n];
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i];
            mincost[i]=nums[i];
        }
        for(int op=1;op<n;op++){
            long long cur = 1LL*op*x;
            for(int i=0;i<n;i++){
                mincost[i]=min(mincost[i],nums[(i-op+n)%n]);
                cur += (1LL*mincost[i]);
            }
            ans = min(cur,ans);
        }
        return ans;
    }
};