static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


/*
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
*/





// CompareHeapElements is used for modifying the comparator of priority queue, as per question
// struct CompareHeapElements {
//     bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
//     {
//         if(p1.first<p2.first){
//             return true;
//         }
//         else if(p1.first==p2.first && p1.second<p2.second){
//             return true;
//         }
//         return false;
//     }
// };

class Solution {
    // int calculateSoldierCount(vector<int>&v) {
    //     int l=0, h=v.size()-1;
    //     while(l<=h) {
    //         int mid=l+((h-l)>>1);
    //         if(v[mid]==0) h=mid-1;
    //         else l=mid+1;
    //     }
    //     return l;
    // }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<mat.size();++i){
            int val=lower_bound(mat[i].begin(),mat[i].end(),0,greater<int>())-mat[i].begin();
            pq.push({val,i});
            //pq.push({calculateSoldierCount(mat[i]),i});
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