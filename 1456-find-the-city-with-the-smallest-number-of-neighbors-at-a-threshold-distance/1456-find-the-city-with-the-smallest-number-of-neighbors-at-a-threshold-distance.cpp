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
    int bfs(vector<vector<pair<int,int>>>adj, int source, int n, int thres){
        int count=0;
        vector<bool>vis(n,false);
        queue<pair<int,int>>q;
        q.push({source,0});
        while(!q.empty()){
            pair<int,int> curr=q.front();
            q.pop();
            vis[curr.first]=true;
            if(curr.second>thres) continue;
            for(auto nghbr:adj[curr.first]){
                if(!vis[nghbr.first] and (nghbr.second+curr.second)<=thres){
                    q.push({nghbr.first,(nghbr.second+curr.second)});
                    ++count;
                }
            }
        }
        return count;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto el:edges){
            adj[el[0]].push_back({el[1],el[2]});
            adj[el[1]].push_back({el[0],el[2]});
        }
        int smallestNumOfNeighbours = n-1, city = n-1;
        for(int i=0;i<n;++i){
            int count=bfs(adj,i,n,distanceThreshold);
            if(smallestNumOfNeighbours >= count) {
                smallestNumOfNeighbours = count;
                city = i;
            }
        }
        return city;
    }
};