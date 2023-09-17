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
        vector<vector<bool>>vis(n,vector<bool>(finalMask,false)) ;
        for(int i=0;i<n;++i){
            q.push({i,1<<i});
            vis[i][1<<i]=true;
        }
        int path=0;
        while(!q.empty()){
            ++path;
            int sz=q.size();
            while(sz--){
                auto [node,mask]=q.front();
                q.pop();
                for(int &nghbr:graph[node]){
                    int newMask=mask|(1<<nghbr);
                    if(newMask==finalMask) return path;
                    if(!vis[nghbr][newMask]){
                        q.push({nghbr,newMask});
                        vis[nghbr][newMask]=true;
                    }
                }
            }
        }
        return -1;
    }
};
