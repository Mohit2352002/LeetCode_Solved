class Solution {
    int n;
    vector<vector<int>>dp;
    int helper(vector<int>&nums, int left, int i){
        if(left==1000 and i==n) return 1;
        else if(i>=n) return 0;
        if(dp[i][left]!=-1) return dp[i][left];
        int ans=0;
        ans+=helper(nums,left-nums[i],i+1);
        ans+=helper(nums,left+nums[i],i+1);
        return dp[i][left]=ans;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        dp.resize(n,vector<int>(target+10000,-1));
        return helper(nums,1000+target,0);
    }
};