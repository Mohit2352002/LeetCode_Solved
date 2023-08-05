static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    vector<int>dp;
    int helper(int n){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        for(int i=1;i<=n;++i){
            ans+=(helper(i-1)*helper(n-i));
        }
        return dp[n]=ans;
    }
public:
    int numTrees(int n) {
        dp.resize(n+1,-1);
        return helper(n);
    }
};