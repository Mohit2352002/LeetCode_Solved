static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

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
};