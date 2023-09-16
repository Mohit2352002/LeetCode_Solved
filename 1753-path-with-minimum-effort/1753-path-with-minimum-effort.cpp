static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();




/*
//TLE
class Solution {
    int ans=INT_MAX;
    int n,m;
    vector<vector<int>>vis;
    vector<int>dir={1,0,-1,0,1};
    void dfs(vector<vector<int>>&heights, int i,int j, int curr_path){
        if(i==m-1 and j==n-1) {
            ans=min(ans,curr_path);
            return;
        }
        vis[i][j]=1;
        for(int dr=0;dr<4;++dr){
            int ni=i+dir[dr],nj=j+dir[dr+1];
            if(ni>=0 and ni<m and nj>=0 and nj<n and !vis[ni][nj]){
                dfs(heights,ni,nj,max(curr_path,abs(heights[ni][nj]-heights[i][j])));
            }
        }
        vis[i][j]=0;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        m=heights.size(),n=heights[0].size();
        vis.resize(m,vector<int>(n,0));
        dfs(heights,0,0,0);
        return ans;
    }
};*/




/*
class Solution{
    vector<int>dir={1,0,-1,0,1};
public:
    int minimumEffortPath(vector<vector<int>>&heights){
        int m=heights.size(),n=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dists(m,vector<int>(n,INT_MAX));
        dists[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            int weight=pq.top()[0],i=pq.top()[1],j=pq.top()[2];
            pq.pop();
            if(dists[i][j]<weight) continue;
            if(i==m-1 and j==n-1) return weight;
            for(int dr=0;dr<4;++dr){
                int ni=i+dir[dr],nj=j+dir[dr+1];
                if(ni<0 or ni>=m or nj<0 or nj>=n) continue;
                int newWeight=max(weight, abs(heights[i][j]-heights[ni][nj]));
                if(dists[ni][nj]<=newWeight) continue;
                dists[ni][nj]=newWeight;
                pq.push({newWeight,ni,nj});
            }
        }
        return 0;
    }
};*/




class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>> q;
        q.push({0,{0, 0}});
        dist[0][0] = 0;
        int dr[] = {1, 0, -1, 0, 1};
        while(!q.empty()){
            int curr = -q.top().first,x = q.top().second.first,y = q.top().second.second;
            q.pop();
            if(x == n-1 && y == m-1) return curr;
            for(int i = 0; i < 4; i++){
                int newX = x + dr[i], newY = y + dr[i+1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                    int diff = max(abs(heights[newX][newY] - heights[x][y]), curr);
                    if(dist[newX][newY] > diff){
                        dist[newX][newY] = diff;
                        q.push({-diff,{newX,newY}});
                    }
                }
            }
        }
        return 0;
    }
};




/*
class Solution
{
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    // we have defined the change in coordinate if they move in specific directions 

    bool isvalid(int x, int y, int n, int mid)
    {
        return (x >= 0 && x < n && y >= 0 && y < mid);
        // to check whether on which path we are moving is valid or not 
    }


    bool bfs(vector<vector<int>> heights, int k)
    {
        queue<pair<int, int>> q;
        // queue to perform the BFS logic 
        q.push({0, 0});
        // initially push the first cell of matrix 
        vector<vector<bool>> visited(101, vector<bool>(101, false));
        // make a visisted array initially with all the value false initially 
        visited[0][0] = 1;
        // since it visited , makr it a true  

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            // pick out the front 
            q.pop();
            int cx = curr.first;
            int cy = curr.second;
            // get the current x and y 
            if (cx == heights.size() - 1 && cy == heights[0].size() - 1)
                return true;
            // if we are reached the last index we are done
            // else just go in all 4 direction and check conditions  
            for (int i = 0; i < 4; i++)
            {
                int x = dx[i] + cx;
                int y = dy[i] + cy;
                // each time make new x , y 
                if (isvalid(x, y, heights.size(), heights[0].size()) && !visited[x][y])
                {
                    // if that x,y is valid , just check tah absolute difference is less tha tha mid or not 
                    if (abs(heights[cx][cy] - heights[x][y]) <= k)
                    {
                        visited[x][y] = true;
                        // if yes visit that node 
                        q.push({x, y});
                        // push it in queue 
                    }
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // we have similar binary search template  

        int low = 0;
        int high = 1e6;
        int ans = -1;

        // set high and low  

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // get a mid 
            // apply bfs over that mid value 
            if (bfs(heights, mid))
            {
                // if that bfs on that value return true , it might be our answer , so store it 
                ans = mid;
                high = mid - 1;
                // since we want want min value , high=mid-1
            }
            else
            {
                low = mid + 1;
                // else increase the value and check for it 
            }
        }
        return ans;
        //  return the ans 
    }
};*/







/*
class Solution {
private:
    bool visited[105][105];  // Visited cells tracker
    int directions_x[4] = {0, 1, -1, 0};  // Changes in x coordinate for four directions
    int directions_y[4] = {1, 0, 0, -1};  // Changes in y coordinate for four directions
    int numRows, numCols;  // Number of rows and columns in the matrix

public:

    // Depth-First Search to explore the path with a given limit effort
    void dfs(int x, int y, int limitEffort, vector<vector<int>>& heights){
        if (visited[x][y])
            return;
        visited[x][y] = true;

        // Stop if we've reached the bottom-right cell
        if (x == numRows - 1 && y == numCols - 1)
            return ;

        // Explore each direction (up, down, left, right)
        for (int i = 0; i < 4; i++) {
            int new_x = x + directions_x[i];
            int new_y = y + directions_y[i];

            // Check if the new coordinates are within bounds
            if (new_x < 0 || new_x >= numRows || new_y < 0 || new_y >= numCols)
                continue;
            
            // Go to next cell if the effort is within limit
            int newEffort = abs(heights[x][y] - heights[new_x][new_y]);
            if (newEffort <= limitEffort)
                dfs(new_x, new_y, limitEffort, heights);
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        numRows = heights.size(); 
        numCols = heights[0].size();

        // Bound for our binary search
        int lowerLimit = 0, upperLimit = 1e6;

        while (lowerLimit < upperLimit) {
            int mid = (upperLimit + lowerLimit) / 2;
            memset(visited, 0, sizeof visited);
            dfs(0, 0, mid, heights);

            if (visited[numRows - 1][numCols - 1])
                upperLimit = mid;
            else
                lowerLimit = mid + 1;
        }

        return lowerLimit;
    }
};*/