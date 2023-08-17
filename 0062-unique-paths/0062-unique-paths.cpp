static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();




/*
class Solution {
    vector<int>dir={1,0,1};
    vector<vector<int>>dp;
    int dfs(int i,int j,int m,int n){
        if(i==m-1 and j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=0;k<2;++k){
            int new_i=i+dir[k],new_j=j+dir[k+1];
            if(new_i>=0 and new_i<m and new_j>=0 and new_j<n){
                ans+=dfs(new_i,new_j,m,n);
            }
        }
        return dp[i][j]=ans;
    }
public:
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        return dfs(0,0,m,n);
    }
};*/






class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=m-2;i>=0;--i){
            for(int j=n-2;j>=0;--j){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};