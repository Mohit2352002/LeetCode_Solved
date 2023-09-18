static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#define pii pair<int,int>
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        priority_queue<pii>pq;
        for(int i=0;i<n;++i){
            int sol=0;
            for(int j=0;j<m;++j){
                if(mat[i][j]==1) ++sol;
                else break;
            }
            pq.push({sol,i});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans(k);
        while(k--){
            ans[k]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};