class Solution {
public:
    int numSquares(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(n==0 || n==1 || n==2 || n==3) return n;
        else if(n==4) return 1;
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0,dp[1]=1,dp[2]=2,dp[3]=3,dp[4]=1;
        for(int i=5;i<=n;++i){
            for(int j=1;j*j<=i;++j){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};