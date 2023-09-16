static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();




/*
class Solution {
    int ans=INT_MAX;
    int n,m;
    vector<vector<int>>vis;
    vector<int>dir={1,0,-1,0,1};
    void dfs(vector<vector<int>>&heights, int i,int j, int curr_path){
        if(i==m-1 and j==n-1) {
            ans=min(ans,curr_path);
            return;
        }
        vis[i][j]=1;
        for(int dr=0;dr<4;++dr){
            int ni=i+dir[dr],nj=j+dir[dr+1];
            if(ni>=0 and ni<m and nj>=0 and nj<n and !vis[ni][nj]){
                dfs(heights,ni,nj,max(curr_path,abs(heights[ni][nj]-heights[i][j])));
            }
        }
        vis[i][j]=0;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        m=heights.size(),n=heights[0].size();
        vis.resize(m,vector<int>(n,0));
        dfs(heights,0,0,0);
        return ans;
    }
};*/


class Solution{
    vector<int>dir={1,0,-1,0,1};
public:
    int minimumEffortPath(vector<vector<int>>&heights){
        int m=heights.size(),n=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dists(m,vector<int>(n,INT_MAX));
        dists[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            int weight=pq.top()[0],i=pq.top()[1],j=pq.top()[2];
            pq.pop();
            if(dists[i][j]<weight) continue;
            if(i==m-1 and j==n-1) return weight;
            for(int dr=0;dr<4;++dr){
                int ni=i+dir[dr],nj=j+dir[dr+1];
                if(ni<0 or ni>=m or nj<0 or nj>=n) continue;
                int newWeight=max(weight, abs(heights[i][j]-heights[ni][nj]));
                if(dists[ni][nj]<=newWeight) continue;
                dists[ni][nj]=newWeight;
                pq.push({newWeight,ni,nj});
            }
        }
        return 0;
    }
};
