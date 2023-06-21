/*
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=nums.size();
        if(n==1) return 0;
        vector<pair<int,int>>vec(n);
        long long n_el=0;
        for(int i=0;i<n;++i){
            vec[i]={nums[i],cost[i]};
            n_el+=cost[i];
        }
        sort(vec.begin(),vec.end());
        int i=0,median;
        long long idx=0,ans=0,median_idx=(n_el+1)/2;
        while(idx<median_idx){
            idx+=vec[i++].second;
        }
        median=vec[i-1].first;
        for(i=0;i<n;++i){
            ans+=(1ll*abs(nums[i]-median)*cost[i]);
        }
        return ans;
    }
};
*/











/*
    long long minCost(vector<int>& A, vector<int>& cost) {
        long long l = 1, r = 1000000, res = f(A, cost, 1), x;
        while (l < r) {
            x = (l + r) / 2;
            long long y1 = f(A, cost, x), y2 = f(A, cost, x + 1);
            res = min(y1, y2);
            if (y1 < y2)
                r = x;
            else
                l = x + 1;
        }
        return res;
    }

    long long f(vector<int>& A, vector<int>& cost, int x) {
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
            res += 1L * abs(A[i] - x) * cost[i];
        return res;
    }
 */
















/*
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long ans = 1e18;
        vector<pair<int,int>> v(n);
        for(int i = 0; i < nums.size(); i++)
            v[i] = {nums[i], cost[i]};
        
        sort(v.begin(), v.end());
        vector<long long> pref(n), suff(n);
        long long c_sum = 0, nc = 0;
        for(int i = 0; i < n; i++){
            pref[i] = (v[i].first * c_sum - nc);
            c_sum += (long long)v[i].second;
            nc += (long long)v[i].first * (long long)v[i].second;
        }
        c_sum = 0, nc = 0;
        for(int i = n - 1; i >= 0; i--){
            ans = min(ans, abs(v[i].first * c_sum - nc) + pref[i]);
            c_sum += (long long)v[i].second;
            nc += (long long)v[i].first * (long long)v[i].second;
        }
        return ans;
    }
};
*/













class Solution {
    int ELEMENT_COUNT = 1000002;
public:
    long minCost(vector<int>nums, vector<int>cost) {
        vector<long long>costOfNos(ELEMENT_COUNT,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            costOfNos[nums[i]] += cost[i];
        }
        
        vector<long long> prefSum(ELEMENT_COUNT);
        vector<long long> suffSum(ELEMENT_COUNT);
        long long ans  = LONG_MAX;
        long long sum = 0;
        for(int i=1;i<ELEMENT_COUNT;i++){
            prefSum[i] = prefSum[i-1] + sum;
            sum += costOfNos[i];
        }
        sum = 0;
        for(int i=ELEMENT_COUNT-2;i>=0;i--){
            suffSum[i] = suffSum[i+1] + sum;
            sum += costOfNos[i];
            ans = min(ans, suffSum[i] + prefSum[i]);
        }
        return ans;
        
    }
};