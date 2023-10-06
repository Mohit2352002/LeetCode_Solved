class Solution {
    vector<int>dp;
    int helper(int n){
        if(n<=4) return n;
        long long ans=1;
        for(int i=1;i<=n/2;++i){
            if(dp[i]==-1) dp[i]=integerBreak(i);
            if(dp[n-i]==-1) dp[n-i]=integerBreak(n-i);
            ans=max({ans,1ll*dp[i]*dp[n-i],1ll*i*(n-i)});
        }
        return dp[n]=ans;
    }
public:
    int integerBreak(int n) {
        dp.resize(n+1,-1);
        long long ans=1;
        for(int i=1;i<=n/2;++i){
            if(dp[i]==-1) dp[i]=helper(i);
            if(dp[n-i]==-1) dp[n-i]=helper(n-i);
            ans=max({ans,1ll*dp[i]*dp[n-i],1ll*i*(n-i)});
        }
        return dp[n]=ans;
    }
};