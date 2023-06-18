class Solution {
public:
    int mod = 1000000007,n,m;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    bool isvalid(int x, int y){
        if(x<0 or x>=n or y<0 or y>=m) return false;
        return true;
    }
    int dfs(int x, int y, vector <vector<int>>&grid,vector <vector<int>>&dp){
        if(dp[x][y]!=-1) return dp[x][y];
        int ans = 1;
        for(int i = 0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(isvalid(nx,ny) and grid[x][y]<grid[nx][ny]){
                ans = (ans+dfs(nx,ny,grid,dp))%mod;
            }
        }
        return dp[x][y] = ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector <vector <int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        long long count = 0;
        n=grid.size(),m=grid[0].size();
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                count = (count + dfs(i,j,grid,dp))%mod;
            }
        }
        return (int)count%mod;
    }
};