static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long,int>mp; //index(n*ycoord+xcoord)=>countofblack
        for(auto c: coordinates) {
            if(c[0]<m-1 && c[1]<n-1) ++mp[1000000L*c[1] +c[0]];          
            if(c[0]-1>=0 && c[1]<n-1) ++mp[1000000L*c[1] +(c[0]-1)];
            if(c[0]<m-1 && c[1]-1>=0) ++mp[1000000L*(c[1]-1) +c[0]];
            if(c[0]-1>=0 && c[1]-1>=0) ++mp[1000000L*(c[1]-1) +(c[0]-1)];
        }
        vector<long long>ans(5,0);
        long long zeroes=1ll*(n-1)*(m-1);
        for(auto el:mp){
            ++ans[el.second];
            --zeroes;
        }
        ans[0]=zeroes;
        return ans;
    }
};