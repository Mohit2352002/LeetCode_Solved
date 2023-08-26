class Solution {
    int n;
    vector<int>dp;
    int helper(vector<vector<int>>& pairs, int i){
        if(i>=n) return 0;
        int ans=0;
        if(dp[i]!=-1) return dp[i];
        for(int j=i+1;j<n;++j){
            if(pairs[i][1]<pairs[j][0]) ans=max(ans,1+helper(pairs,j));
            ans=max(ans,helper(pairs,j));
        }
        return dp[i]=ans;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        dp.resize(n,-1);
        sort(pairs.begin(),pairs.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        int ans=0;
        for(int i=0;i<n;++i) ans=max(ans,helper(pairs,i));
        return ans+1;
    }
};