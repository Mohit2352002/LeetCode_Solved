static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
    vector<vector<int>>dp;
    int helper(vector<vector<int>>&grid,int i,int j){
        int m=grid.size(),n=grid[0].size();
        if(i==m-1 and j==n-1) return 1;
        else if(i>=m or j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(grid[i][j]==1) return 0;
        return dp[i][j]=helper(grid,i+1,j)+helper(grid,i,j+1);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1 or obstacleGrid[0][0]==1) return 0;
        dp.resize(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return helper(obstacleGrid,0,0);
    }
};*/



class Solution {
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(grid[m-1][n-1]==1 or grid[0][0]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]!=1){
                    if(i-1>=0) dp[i][j]+=dp[i-1][j];
                    if(j-1>=0) dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};