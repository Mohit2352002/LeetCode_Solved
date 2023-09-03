static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// class Solution {
// public:
//     int minTaps(int n, vector<int>& ranges) {
//         vector<int>dp(n+1,n+2);
//         dp[0]=0;
//         for(int i=0;i<=n;++i){
//             for(int j=max(0,i-ranges[i] +1) ;j<=min(n,i+ranges[i]);++j){
//                 dp[j]=min(dp[j],dp[max(0,i-ranges[i])]+1);
//             }
//         }
//         return dp[n]<(n+2)?dp[n]:-1;
//     }
// };



class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1,n+2);
        dp[0]=0;
        for(int i=0;i<=n;++i){
            int start=max(0,i-ranges[i]),end=min(n,i+ranges[i]);
            for(int j=start;j<=end;++j){
                dp[j]=min(dp[j],1+dp[max(0,i-ranges[i])]);
            }
        }
        return dp[n]<(n+2)?dp[n]:-1;
    }
};