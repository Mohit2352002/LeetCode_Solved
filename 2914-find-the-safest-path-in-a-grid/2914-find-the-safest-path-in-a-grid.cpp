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











/*
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
};*/











class Solution {
private : 
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    //This function finds the minimum Distance of each cell from any thief cell.
    //Multisource BFs from the theif cells gives the minimum Distance. 
    //TC : O(N*N)
    //Iterating and pushing the theif cells takes O(N*N) time. 
    //Finding the Minimum Disance from theif cell to each cell takes O(N*N) time. 
    //SC : O(N*N)
    //space for the distance and the Vsiited matrix.

    void findMinimumDistance(vector<vector<int>> &grid,vector<vector<int>> &distance)
    {
        int n = grid.size();
        /*visited array to avoid duplicate visits*/
        vector<vector<int>> visited(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        /*Taking all the thief cells into the queue*/
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                if(grid[i][j])
                {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        /*Doing multi surface BFs and updating the distance when the cell is visited first*/
        for(int dist = 0; !q.empty(); ++dist)
        {
            for(int i = q.size(); i > 0; --i)
            {
                auto it = q.front();
                q.pop();
                int x = it.first, y = it.second;
                distance[x][y] = dist;
                for(int j = 0; j<4; ++j)
                {
                    int nx = x + dx[j], ny = y + dy[j];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0)
                    {
                        q.push({nx,ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
    }
    //This function will return if there exists a path in the grid whose maximum safeness 
    //factor is >= k
    //We do BFs to explore all the paths starting from the (0,0).
    //Consider only the cells in the path whose distance from the any thief cell is >= k.

    //TC : O(N*N)
    //At max while loop runs for O(N*N) time.
    //SC : O(N*N)
    //space for the queue and the visited matrix.
    bool isPathExists(int n,vector<vector<int>> &distance,int k)
    {  
        queue<pair<int,int>> q;
        /*If the cell (0,0) distance from theif cell is < k then In any path we choose the cell (0,0)
        is present, so there is no path in grid with each cell >= k minimum distance from any thief*/
        if(distance[0][0] < k) return false;
        q.push({0,0});
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;
            if(x == n-1 && y == n-1) return true;
            for(int j = 0; j<4; ++j)
            {
                int nx = x + dx[j], ny = y + dy[j];
                /*Take into queue only when the Manhatten distance >= k from current cell to thief cell*/
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && 
                visited[nx][ny] == 0 && distance[nx][ny] >= k)
                {
                    q.push({nx,ny});
                    visited[nx][ny] = 1; 
                }
            }
        }
        return false;
    }
public:
    //TC : O(N*N + O(N*N)log(2*n-1))
    //N*N for finding the minimum Distance of each cell to any thief cell.
    //N*Nlog(2*n-1) for finding the maximum safeness factor of all paths. 
    //SC : O(N*N)
    //Space used for the distance,visited matrix and the queue.
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance(n,vector<int>(n));
        findMinimumDistance(grid,distance);
        //Range of binary search 
        //Max distance between any two cells is equal to distance b/w (0,0) and (n-1,n-1). 
        //Manhatten distance b/w them is 2*n-1.
        //Min Distance is 0.
        //So low = 0 high = 2*n-1
        int low = 0,high = 2*n-1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            isPathExists(n,distance,mid) ? low = mid + 1 : high = mid-1;
        }
        return high;
    }
};