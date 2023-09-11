static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>mp;
        int n=groupSizes.size();
        for(int i=0;i<n;++i) mp[groupSizes[i]].push_back(i);
        vector<vector<int>>ans;
        for(auto el:mp){
            int groups=el.second.size()/el.first;
            int i=-1;
            while(groups--){
                vector<int>temp(el.first);
                for(int j=0;j<el.first;++j){
                    temp[j]=el.second[++i];
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};