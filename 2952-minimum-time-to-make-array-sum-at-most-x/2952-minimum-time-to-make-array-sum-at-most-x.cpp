static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
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