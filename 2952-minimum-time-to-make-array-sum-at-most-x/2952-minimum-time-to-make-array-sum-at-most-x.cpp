static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        if (sum1 <= x) return 0;
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int n = nums1.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i].first = nums1[i];
            arr[i].second = nums2[i];
        }
        sort(arr.begin(), arr.end(), [](const auto& l, const auto& r) -> bool {
            return l.second < r.second;
        });
        int dp[n][n + 1];// dp[index][operations]
        memset(dp, 0, sizeof(dp));
        dp[0][1] = arr[0].first + arr[0].second;
        for (int i = 1; i < n; i++) {
            for (int op=1;op<=i;op++) {
                dp[i][op]=max(dp[i-1][op],dp[i-1][op-1]+arr[i].first+arr[i].second*op);
            }
            dp[i][i+1] = max(dp[i-1][i+1],dp[i-1][i]+arr[i].first+arr[i].second*(i+1));
        }
        for (int j = 1; j <= n; j++) {
            if (sum1 + sum2 * j - dp[n - 1][j] <= x) return j;
        }
        return -1;
    }
};/*









class Solution {
    vector<vector<int>>dp;
    vector<pair<int,int>>vec;
    int helper(int op, int ind){
        if(op==0 or ind<0) return 0;
        if(dp[op][ind]!=-1) return dp[op][ind];
        int prev_max=helper(op,ind-1);
        int taking_curr=vec[ind].second+(op*vec[ind].first)+helper(op-1,ind-1);
        return dp[op][ind]=max(prev_max,taking_curr);
    }
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        long long n=nums1.size(),sum2=0,sum1=0;
        for(int i=0;i<n;++i){
            sum1+=nums1[i];
            sum2+=nums2[i];
            vec.push_back({nums2[i],nums1[i]});
        }
        if(sum1<=x) return 0;
        sort(vec.begin(),vec.end(),[&](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first) return a.second>b.second;
            return a.first<b.first;
        });
        dp.resize(n+1,vector<int>(n,-1));
        for(int op=1;op<=n;++op){
            if(sum1+(op*sum2)-helper(op,n-1)<=x) return op;
        }
        return -1;
    }
};*/