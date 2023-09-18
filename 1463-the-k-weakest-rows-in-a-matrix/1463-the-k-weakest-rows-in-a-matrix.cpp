static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        int n=mat.size();
        for(int i=0;i<n;++i){
            int val=lower_bound(mat[i].begin(),mat[i].end(),0,greater<int>())-mat[i].begin();
            pq.push({val,i});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans(k);
        while(pq.size()){
            ans[--k]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};