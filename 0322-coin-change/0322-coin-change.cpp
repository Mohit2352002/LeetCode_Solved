static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
    int n;
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
};*/




class Solution{
    public:
    int coinChange(vector<int>&coins, int amount){
        if(amount==0) return 0;
        int n=coins.size(),inf=amount+1;
        vector<int>dp(amount+1,inf);
        sort(begin(coins), end(coins));
        dp[0]=0;
        for(int val=1;val<=amount;++val){
            for(int i=0;i<n;++i){
                if(coins[i]<=val){
                    dp[val]=min(dp[val],1+dp[val-coins[i]]);
                }else break;
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};