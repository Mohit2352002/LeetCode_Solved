static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] or grid[n-1][n-1]) return 0;
        vector<pair<int,int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]){
                    dist[i][j]=0;
                    q.push({i,j});
                    vis[i][j]=1;
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
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({dist[0][0],{0,0}});
        vis[0][0]=1;
        while(!pq.empty()){
            int dis=pq.top().first,i=pq.top().second.first,j=pq.top().second.second;
            pq.pop();
            for(auto &dir:dirs){
                int ni=i+dir.first,nj=j+dir.second;
                if(ni>=0 and nj>=0 and nj<n and ni<n and !vis[ni][nj]){
                    if(ni==n-1 and nj==n-1) return min(dis,dist[ni][nj]);
                    vis[ni][nj]=1;
                    pq.push({min(dis,dist[ni][nj]),{ni,nj}});
                }
            }
        }
        return 0;
    }
};*/


class Solution {
public:
int maximumSafenessFactor(vector<vector<int>>& g) {
    queue<array<int, 2>> q;
    int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
    if(g[0][0] and g[n-1][n-1]) return 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j])
                q.push({i, j});
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && (g[x][y] == 0 ||  g[x][y] > g[i][j] + 1)) {
                g[x][y] = g[i][j] + 1;
                q.push({x, y});
            }
        }
    }
    priority_queue<array<int, 3>> pq;
    pq.push({g[0][0], 0, 0});
    g[0][0]=-1;
    while (!pq.empty()) {
        auto [sf, i, j] = pq.top(); 
        if(i==n-1 and j==n-1) return sf-1;
        pq.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] != -1 && g[x][y] != 1) {
                pq.push({min(sf, g[x][y]), x, y});
                g[x][y] = -1; 
            }
        }
    }
    return 0;
}
};