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
};