static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();





/*
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        
        // Building the graph (adjacency list). 
        for (const auto& road: roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        
        int maximal = 0;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Sum of neighbors (connected cities) of both cities. 
                int network_rank = graph[i].size() + graph[j].size();
                
                // Reduce the rank by 1 in case the cities are connected to each other.
                if (graph[j].count(i)) {
                    --network_rank;
                }
                
                // Maximal network rank is the maximum network rank possible.
                maximal = max(maximal, network_rank);
            }
            
        }
        return maximal;
    }
};*/








class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>graph(n,vector<int>(n,0));
        vector<int>degree(n,0);
        int sz=roads.size(),ans=0;
        for(int i=0;i<sz;i++){
            int u=roads[i][0],v=roads[i][1];
            degree[u]++;
            degree[v]++;
            if(u<v) graph[u][v]=1;
            else graph[v][u]=1;
        }
        for(int i=0;i<graph.size();i++){
            for(int j=i+1;j<graph.size();j++){
                int rank=degree[i]+degree[j]-graph[i][j];
                ans=max(ans,rank);
            }
        }
        return ans;
    }
};