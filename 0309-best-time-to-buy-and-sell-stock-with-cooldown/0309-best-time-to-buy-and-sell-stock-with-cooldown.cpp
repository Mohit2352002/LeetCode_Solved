class Solution {
    vector<vector<int>>dp;
    int helper(vector<int>&nums,int i,bool buy){
        if(i>=nums.size()) return 0;
        if(dp[buy][i]!=-1) return dp[buy][i];
        if(buy) return dp[buy][i]=max(helper(nums,i+1,false)-nums[i],helper(nums,i+1,true));
        else return dp[buy][i]=max(helper(nums,i+2,true)+nums[i],helper(nums,i+1,false));
    }
public:
    int maxProfit(vector<int>& prices) {
        dp.resize(2,vector<int>(prices.size(),-1));
        return helper(prices,0,true);
    }
};