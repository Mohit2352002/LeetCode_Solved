static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    int mod=1e9+7;
    int helper(int n, int x, int num,vector<vector<int>>&dp){
        if(n==0 || pow(num,x)==n) return 1;
        if(num>n or n<0 or pow(num,x)>n) return 0;
        if(dp[n][num]!=-1) return dp[n][num];
        long long temp=pow(num,x);
        return dp[n][num]=(helper(n-temp,x,num+1,dp) + helper(n,x,num+1,dp))%mod;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(n,x,1,dp);
    }
};