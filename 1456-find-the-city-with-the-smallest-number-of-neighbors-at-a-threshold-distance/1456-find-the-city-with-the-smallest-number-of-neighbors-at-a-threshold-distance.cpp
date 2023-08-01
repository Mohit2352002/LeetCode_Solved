//Floyd Warshall Algorithm
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(auto el:edges){
            dp[el[0]][el[1]]=el[2];
            dp[el[1]][el[0]]=el[2];
        }
        for(int i=0;i<n;++i) dp[i][i]=0;
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(dp[i][k]!=INT_MAX and dp[k][j]!=INT_MAX)
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int idx=-1,maxi=INT_MAX;
        for(int i=0;i<n;++i){
            int count=0;
            for(int j=0;j<n;++j){
                if(i!=j and dp[i][j]<=dt) ++count;
            }
            if(maxi>=count){
                idx=i;
                maxi=count;
            }
        }
        return idx;
    }
};*/
class Solution {
public:
    
	// This return  the count of cities we can visit from source
	// with distance at most equal to threshold
    int bfs(vector<vector<pair<int, int>>>& adj, int source, int threshold, const int& n) {
        int count = 0;
        
        queue<pair<int, int>> q;
        vector<bool> vis(n, false);
        q.push({source, 0});
        
        while(q.size()) {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            vis[node] = true;
            
            if(distance > threshold) continue;
            
            for(auto& it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                
                if(!vis[adjNode] and wt + distance <= threshold){
                    q.push({adjNode, wt + distance});
                    count++;                
                }
            }
        }
        
        return count;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int smallestNumOfNeighbours = n-1, city = n-1;
        
		// Get count for each city and return the one with smallest count
        for(int i=0; i<n; i++) {
            int count = bfs(adj, i, distanceThreshold, n); 
            if(smallestNumOfNeighbours >= count) {
                smallestNumOfNeighbours = count;
                city = i;
            }
        }
        return city;
    }
};