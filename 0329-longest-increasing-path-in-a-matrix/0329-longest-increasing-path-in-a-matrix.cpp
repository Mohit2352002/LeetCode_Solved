class Solution {
    int m,n,ans=1;
    int dp[201][201];
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool isValid(int i, int j){
        return (i>=0 and i<n and j>=0 and j<m);
    }
    int dfs(int x, int y, vector<vector<int>>& matrix){
        if(dp[x][y]!=-1) return dp[x][y];
        int res=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(isValid(nx,ny) and matrix[nx][ny]>matrix[x][y]){
                res=max(1+dfs(nx,ny,matrix),res);
            }
        }
        ans=max(ans,res);
        return dp[x][y]=res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size(),m=matrix[0].size();
        if(m==1 and n==1) return 1;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                ans=max(ans,dfs(i,j,matrix));
            }
        }
        return ans;
    }
};