static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] or grid[n-1][n-1]) return 0;
        vector<pair<int,int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            for(auto &dir:dirs){
                int ni=i+dir.first,nj=j+dir.second;
                if(ni>=0 and nj>=0 and nj<n and ni<n and dist[ni][nj]>dist[i][j]+1){
                    q.push({ni,nj});
                    dist[ni][nj]=dist[i][j]+1;
                }
            }
        }
        vector<vector<int>>vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({dist[0][0],{0,0}});
        vis[0][0]=1;
        int ans=1e9;
        while(!pq.empty()){
            int dis=pq.top().first,i=pq.top().second.first,j=pq.top().second.second;
            pq.pop();
            ans=min(ans,dis);
            if(i==n-1 and j==n-1) return ans;
            for(auto &dir:dirs){
                int ni=i+dir.first,nj=j+dir.second;
                if(ni>=0 and nj>=0 and nj<n and ni<n and !vis[ni][nj] and !grid[ni][nj]){
                    if(ni==n-1 and nj==n-1) return min(ans,dist[ni][nj]);
                    vis[ni][nj]=1;
                    pq.push({dist[ni][nj],{ni,nj}});
                }
            }
        }
        return 0;
    }
};