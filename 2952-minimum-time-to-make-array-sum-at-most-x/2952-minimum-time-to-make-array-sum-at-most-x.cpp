static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


/*
class Solution {
    vector<vector<long long>>dp;
    vector<int>vec1,vec2;
    long long helper(int oper, int last_idx){
        if(oper==0 or last_idx<0) return 0;
        if(dp[oper][last_idx]!=-1) return dp[oper][last_idx];
        return dp[oper][last_idx]=max(helper(oper,last_idx-1),vec1[last_idx]+oper*vec2[last_idx]+helper(oper-1,last_idx-1));
    }
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        vector<pair<int,int>>vec;
        long long n=nums1.size(),sum2=0,sum1=0;
        for(int i=0;i<n;++i){
            sum1+=nums1[i];
            sum2+=nums2[i];
            vec.push_back({nums2[i],nums1[i]});
        }
        sort(vec.begin(),vec.end());
        dp.resize(n+1,vector<long long>(n,-1));
        vec1.resize(n),vec2.resize(n);
        for(int i=0;i<n;++i){
            vec1[i]=vec[i].second;
            vec2[i]=vec[i].first;
        }
        for(int op=0;op<=n;++op){
            long long sum=sum1+(op*sum2);
            if(sum-(helper(op,n-1))<=x) return op;
        }
        return -1;
    }
};











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
        int dp[n][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = arr[0].first + arr[0].second;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + arr[i].first + arr[i].second * j);
            }
            dp[i][i + 1] = dp[i - 1][i] + arr[i].first + arr[i].second * (i + 1);
        }
        for (int j = 1; j <= n; j++) {
            if (sum1 + sum2 * j - dp[n - 1][j] <= x) return j;
        }
        return -1;
    }
};*/







class Solution {
    vector<vector<int>>dp;
    vector<int>vec1,vec2;
    int helper(int op, int ind){
        if(op==0 or ind<0) return 0;
        if(dp[op][ind]!=-1) return dp[op][ind];
        int prev_max=helper(op,ind-1);
        int taking_curr=vec1[ind]+(op*vec2[ind])+helper(op-1,ind-1);
        return dp[op][ind]=max(prev_max,taking_curr);
    }
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        vector<pair<int,int>>vec;
        long long n=nums1.size(),sum2=0,sum1=0;
        vec1.resize(n);
        vec2.resize(n);
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
        for(int i=0;i<n;++i){
            vec1[i]=vec[i].second;
            vec2[i]=vec[i].first;
        }
        dp.resize(n+1,vector<int>(n,-1));
        for(int op=1;op<=n;++op){
            if(sum1+(op*sum2)-helper(op,n-1)<=x) return op;
        }
        return -1;
    }
};