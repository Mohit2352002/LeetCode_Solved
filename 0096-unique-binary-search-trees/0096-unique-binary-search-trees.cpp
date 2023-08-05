static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
    /*int helper(int n){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        for(int i=1;i<=n;++i){
            ans+=(helper(i-1)*helper(n-i));
        }
        return dp[n]=ans;
    }//*
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;++i){
            for(int root=1;root<=i;++root){
                dp[i]+=(dp[root-1]*dp[i-root]);
            }
        }
        return dp[n];
    }
};*/






class Solution {
public:
    long ncr(int n, int r) {
        long ans = 1;
        for(int i = 0; i < r; i++) {
            ans *= n-i;
            ans /= i+1;
        }
        return ans;   
    }
    int numTrees(int n) {
        return ncr(2*n, n) / (n + 1);
    }
};