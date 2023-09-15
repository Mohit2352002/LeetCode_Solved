static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    vector<vector<pair<int,int>>>adj;
    int n;
    int mst(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<bool>vis(n,false);
        int sum=0;
        while(!pq.empty()){
            int weight=pq.top().first,node=pq.top().second;
            pq.pop();
            if(vis[node]==true) continue;
            sum+=weight;
            vis[node]=true;
            for(auto &nghbr:adj[node]){
                if(vis[nghbr.first]==false){
                    pq.push({nghbr.second,nghbr.first});
                }
            }
        }
        return sum;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        n=points.size();
        adj.resize(n);
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        return mst();
    }
};