static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    vector<vector<bool>>vis;
    int n,m;
    vector<int>dir={1,0,-1,0,1};
    void dfs(vector<vector<char>>&grid,int i,int j){
        for(int k=0;k<4;++k){
            int di=i+dir[k],dj=j+dir[k+1];
            if(di>=0 and dj>=0 and di<m and dj<n and !vis[di][dj] and grid[di][dj]=='1'){
                vis[di][dj]=1;
                dfs(grid,di,dj);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n=grid[0].size(),m=grid.size();
        vis.resize(m,vector<bool>(n,0));
        int count=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!vis[i][j] and grid[i][j]=='1'){
                    vis[i][j]=1;
                    dfs(grid,i,j);
                    ++count;
                }
            }
        }
        return count;
    }
};