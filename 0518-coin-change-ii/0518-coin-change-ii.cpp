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
        if(value==0) return 1;
        if(dp[value][idx]!=-1) return dp[value][idx];
        int counts=0;
        for(int i=0;i<=idx;++i){
            if(value-coins[i]>=0) counts+=helper(value-coins[i],i,coins);
        }
        return dp[value][idx]=counts;
    }
public:
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.resize(amount+1,vector<int>(n+1,-1));
        return helper(amount,n-1,coins);
    }
};
/*
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        dp[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};*/