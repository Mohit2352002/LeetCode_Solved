class Solution {
    int mod=1e9+7,n,m;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<int>>dp;
    bool isvalid(int x, int y){
        if(x>=0 and x<n and y>=0 and y<m) return true;
        return false;
    }
    int dfs(int x, int y, vector<vector<int>>& grid){
        if(dp[x][y]!=-1) return dp[x][y];
        int ans=1;
        for(int i=0;i<4;++i){
            int nx=x+dx[i], ny=y+dy[i];
            if(isvalid(nx,ny) and grid[x][y]<grid[nx][ny]){
                ans=(ans+dfs(nx,ny,grid))%mod;
            }
        }
        return dp[x][y]=ans;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        n=grid.size(), m=grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        long long count=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                count=(count+dfs(i,j,grid))%mod;
            }
        }
        return (int) count;
    }
};