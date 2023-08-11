static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
    int n;
    vector<vector<int>>dp;
    int helper(int value, int idx, vector<int>&coins){
        if(value<0) return 0;
        if(value==0) return 1;
        if(dp[value][idx]!=-1) return dp[value][idx];
        int counts=0;
        for(int i=0;i<=idx;++i){
            counts+=helper(value-coins[i],i,coins);
        }
        return dp[value][idx]=counts;
    }
public:
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.resize(amount+1,vector<int>(n+1,-1));
        sort(coins.begin(),coins.end());
        return helper(amount,n-1,coins);
    }
};