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
        int sz=roads.size(),ans=0;
        vector<vector<int>>gr(n);
        map<pair<int,int>,bool>mp;
        for(int i=0;i<sz;++i){
            gr[roads[i][0]].push_back(roads[i][1]);
            gr[roads[i][1]].push_back(roads[i][0]);
            if(roads[i][0]<roads[i][1]) mp[{roads[i][0],roads[i][1]}]=true;
            else mp[{roads[i][1],roads[i][0]}]=true;
        }
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int curr=gr[i].size()+gr[j].size();
                if(mp[{i,j}]) --curr;
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};*/






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
};