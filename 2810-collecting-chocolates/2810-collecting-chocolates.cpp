class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long cost, cost1, l = 0, r = nums.size();
        while (l < r) {
            long long m = (l + r) / 2;
            cost = m * x, cost1 = (m + 1) * x;
            deque<int> d; 
            for (int i = 0; i < nums.size() + m + 1; ++i) {
                while (!d.empty() && d.back() > nums[i % nums.size()])
                    d.pop_back();
                d.push_back(nums[i % nums.size()]);
                if (i >= m + 1) {
                    cost1 += d.front();
                    if (d.front() == nums[i - m - 1])
                        d.pop_front();
                }
                if (i >= m && i < nums.size() + m)
                    cost += d.front();
            }
            if (cost > cost1)
                l = m + 1;
            else
                r = m;
        }
        return min(cost, cost1);
    }  
};







/*
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
};*/