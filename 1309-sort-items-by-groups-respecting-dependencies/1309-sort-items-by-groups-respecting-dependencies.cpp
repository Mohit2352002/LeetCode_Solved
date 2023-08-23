 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    vector<int>topo(unordered_map<int,vector<int>>&adj,vector<int>&indegree){
        queue<int>q;
        vector<int>ans;
        int n=indegree.size();
        for(int i=0;i<n;++i){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            ans.push_back(curr);
            q.pop();
            for(auto neighbr:adj[curr]){
                --indegree[neighbr];
                if(indegree[neighbr]==0) q.push(neighbr);
            }
        }
        return (ans.size()==n)?ans:vector<int>();
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //assigning groups to items with no group or -1 as group
        for(int i=0;i<n;++i){
            if(group[i]==-1) group[i]=m++;
        }

        //creating and filling graph for beforeItems and groupItems and resp indegrees
        vector<int>itemIndegree(n,0),groupIndegree(m,0);
        unordered_map<int,vector<int>>itemGraph,groupGraph;
        for(int i=0;i<n;++i){
            for(int prev:beforeItems[i]){
                ++itemIndegree[i];
                itemGraph[prev].push_back(i);
                if(group[i]!=group[prev]){
                    ++groupIndegree[group[i]];
                    groupGraph[group[prev]].push_back(group[i]);
                }
            }
        }

        //getting itemOrder and groupOrder using topological sorting
        vector<int>itemOrder=topo(itemGraph,itemIndegree);
        vector<int>groupOrder=topo(groupGraph,groupIndegree);
        if(itemOrder.empty() or groupOrder.empty()) return {};

        vector<int>res;
        unordered_map<int,vector<int>>groupItemMap;
        for(int item:itemOrder){
            groupItemMap[group[item]].push_back(item);
        }
        for(int i=0;i<m;++i){
            int curr_group=groupOrder[i];
            for(int j=0;j<groupItemMap[curr_group].size();++j){
                res.push_back(groupItemMap[curr_group][j]);
            }
        }
        return res;
    }
};