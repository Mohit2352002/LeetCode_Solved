static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(auto el:edges){
            dp[el[0]][el[1]]=el[2];
            dp[el[1]][el[0]]=el[2];
        }
        for(int i=0;i<n;++i) dp[i][i]=0;
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(dp[i][k]!=INT_MAX and dp[k][j]!=INT_MAX)
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        vector<int>count(n,0);
        int idx=-1,maxi=INT_MAX;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i!=j and dp[i][j]<=dt) ++count[i];
            }
            if(maxi>=count[i]){
                idx=i;
                maxi=count[i];
            }
        }
        return idx;
    }
};