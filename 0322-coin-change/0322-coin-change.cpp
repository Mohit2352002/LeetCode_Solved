class Solution {
    int n,ans=1e6;
    vector<vector<int>>dp;
    int helper(vector<int>&coins, int amount, int idx){
        if(amount==0) return 0;
        if(idx==n or amount<0) return 1e6;
        if(dp[amount][idx]!=-1) return dp[amount][idx];
        int take=1+helper(coins, amount-coins[idx], idx);
        int skip=helper(coins,amount,idx+1);
        return dp[amount][idx]=min(take,skip);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        n=coins.size();
        dp.resize(amount+1,vector<int>(n,-1));
        int ans=helper(coins,amount,0);
        return ans==1e6?-1:ans;
    }
};