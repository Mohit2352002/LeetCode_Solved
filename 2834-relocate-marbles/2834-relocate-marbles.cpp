static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int n=nums.size(),m=moveFrom.size();
        unordered_map<int,int>mp;//position->count;
        for(int i=0;i<n;++i){
            ++mp[nums[i]];
        }
        cout<<endl<<endl;
        for(int i=0;i<m;++i){
            if(moveTo[i]==moveFrom[i]) continue;
            mp[moveTo[i]]=mp[moveTo[i]]+mp[moveFrom[i]];
            mp[moveFrom[i]]=0;
        }
        vector<int>ans;
        for(auto el:mp){
            if(el.second) ans.push_back(el.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};