static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n=items.size();
        if(n==1) return items[0][0]+1;
        sort(items.begin(),items.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]>b[0];
        });
        long long ans=0,cur=0;
        vector<int>dup;
        unordered_set<int>seen;
        for(int i=0;i<n;++i){
            if(i<k){
                cur+=items[i][0];
                if(seen.find(items[i][1])!=seen.end()) dup.push_back(items[i][0]);
            }else if(seen.find(items[i][1])==seen.end()){
                if(dup.empty()) break;
                cur+=(items[i][0]-dup[dup.size()-1]);
                dup.pop_back();
            }
            seen.insert(items[i][1]);
            ans=fmax(ans,cur+(1ll*seen.size()*seen.size()));
        }
        return ans;
    }
};