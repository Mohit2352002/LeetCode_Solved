static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1 or n==0) return 0;
        int finalMask=(1<<n)-1;
        queue<pair<int,int>>q;//pair of {node,mask}
        set<pair<int,int>>vis;
        for(int i=0;i<n;++i){
            int curr_mask=1<<i;
            q.push({i,curr_mask});
            vis.insert({i,curr_mask});
        }
        int path=0;
        while(!q.empty()){
            ++path;
            int sz=q.size();
            while(sz--){
                auto [node,mask]=q.front();
                q.pop();
                for(const int &nghbr:graph[node]){
                    int newMask=(mask|(1<<nghbr));
                    if(vis.find({nghbr,newMask})!=vis.end()) continue;
                    if(newMask==finalMask) return path;
                    q.push({nghbr,newMask});
                    vis.insert({nghbr,newMask});
                }
            }
        }
        return path;
    }
};