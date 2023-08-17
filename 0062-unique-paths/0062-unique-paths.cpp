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
};