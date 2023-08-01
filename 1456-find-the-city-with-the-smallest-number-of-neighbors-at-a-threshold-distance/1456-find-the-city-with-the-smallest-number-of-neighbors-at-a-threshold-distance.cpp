static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();




/*
//Floyd Warshall Algorithm
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
                    if(i==j or i==k or j==k) continue;
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
};//*/







/*
//BFS on every node
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
};//*/







/*
//Bellman Ford Algorithm
class Solution {
public:
    int findTheCity(int n,vector<vector<int>>&edges, int thres){
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        for(int source=0;source<n;++source){
            dist[source][source]=0;
            for(int itr=1;itr<n;++itr){
                for(auto el:edges){
                    if(dist[source][el[0]]+ el[2] < dist[source][el[1]]){
                        dist[source][el[1]]=dist[source][el[0]]+el[2];
                    }
                    if(dist[source][el[1]]+el[2]<dist[source][el[0]]){
                        dist[source][el[0]]=dist[source][el[1]]+el[2];
                    }
                }
            }
        }
        int minCity = -1;
        int minCount = n;
        for (int i = 0; i < n; i++) {
            int curCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dist[i][j] <= thres) ++curCount;
            }
            if (curCount <= minCount) {
                minCount = curCount;
                minCity = i;
            }
        }
        return minCity;
    }
};//*/








/*
//SPFA (shortest path fastest algoritm) Improved Bellman Ford Algorithm
class Solution {
public:
    int findTheCity(int n,vector<vector<int>>&edges, int thres){
        vector<vector<pair<int,int>>>adj(n);
        for(auto el:edges){
            adj[el[0]].push_back({el[1],el[2]});
            adj[el[1]].push_back({el[0],el[2]});
        }
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        for(int source=0;source<n;++source){
            dist[source][source]=0;
            queue<int>q;
            q.push(source);
            while (!q.empty()){
                int u = q.front();
                q.pop();
                for (pair<int,int>nghbr : adj[u]) {
                    int v = nghbr.first;
                    int duv = nghbr.second;
                    if (dist[source][v] > dist[source][u] + duv) {
                        dist[source][v] = dist[source][u] + duv;
                        q.push(v);
                    }
                }
            }
        }
        int minCity = -1;
        int minCount = n;
        for (int i = 0; i < n; i++) {
            int curCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dist[i][j] <= thres) ++curCount;
            }
            if (curCount <= minCount) {
                minCount = curCount;
                minCity = i;
            }
        }
        return minCity;
    }
};//*/









///*
class Solution {
public:
    int findTheCity(int n,vector<vector<int>>&edges, int thres){
        vector<vector<pair<int,int>>>adj(n);
        for(auto el:edges){
            adj[el[0]].push_back({el[1],el[2]});
            adj[el[1]].push_back({el[0],el[2]});
        }
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        for(int source=0;source<n;++source){
            dist[source][source]=0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
            pq.push({source, 0});
            while (!pq.empty()) {
                pair<int,int> cur = pq.top();
                pq.pop();
                int u = cur.first;
                int du = cur.second;
                if (du > dist[source][u]) continue;
                for (pair<int,int> ngbhr : adj[u]) {
                    int v = ngbhr.first;
                    int duv = ngbhr.second;
                    if (dist[source][v] > du + duv) {
                        dist[source][v] = du + duv;
                        pq.push({v, dist[source][v]});
                    }
                }
            }
        }
        int minCity = -1;
        int minCount = n;
        for (int i = 0; i < n; i++) {
            int curCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dist[i][j] <= thres) ++curCount;
            }
            if (curCount <= minCount) {
                minCount = curCount;
                minCity = i;
            }
        }
        return minCity;
    }
};//*/