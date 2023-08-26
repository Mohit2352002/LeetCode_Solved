static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    int n;
    vector<int>dp;
    int helper(vector<vector<int>>& pairs, int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int low=i+1,high=n-1;
        while(low<=high){
            int mid=(low+((high-low)>>1));
            if(pairs[i][1]<pairs[mid][0]) high=mid-1;
            else low=mid+1;
        }
        return dp[i]=max(1+helper(pairs,low),helper(pairs,i+1));
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        dp.resize(n,-1);
        sort(pairs.begin(),pairs.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        return helper(pairs,0);
    }
};