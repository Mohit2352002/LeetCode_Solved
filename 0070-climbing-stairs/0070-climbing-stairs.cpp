static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    int dp[46];
public:
    int climbStairs(int n) {
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;++i){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};